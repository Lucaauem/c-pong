#include "window.h"
#include <iso646.h>
#include <windef.h>
#include <windows.h>

unsigned char bitmap[WIDTH * HEIGHT * 3];

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int openWindow(HINSTANCE hInstance, int nCmdShow) {
  SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
  const char CLASS_NAME[] = "pongWindow";

  WNDCLASS wc = {0};
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;

  RegisterClass(&wc);

  RECT rc = {0, 0, WIN_WIDTH, WIN_HEIGHT};
  AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

  HWND hwnd = CreateWindowEx(0, CLASS_NAME, "C-Pong", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);

  if (hwnd == NULL) {
    return 0;
  }

  ShowWindow(hwnd, nCmdShow);
  
  // Adjust client window
  RECT cr;
  GetClientRect(hwnd, &cr);
  int dx = WIN_WIDTH - (cr.right - cr.left);
  int dy = WIN_HEIGHT - (cr.bottom - cr.top);

  if(dx != 0 || dy != 0) {
    RECT wr;
    GetWindowRect(hwnd, &wr);
    SetWindowPos(hwnd, NULL, 0, 0, (wr.right - wr.left) + dx, (wr.bottom - wr.top) + dy, SWP_NOMOVE | SWP_NOZORDER);
  }

  MSG msg = {0};
  DWORD lastTime = GetTickCount();

  while (1) {
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
      if (msg.message == WM_QUIT) {
        return 0;
      }
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }

    DWORD currentTime = GetTickCount();
    if (currentTime - lastTime >= FRAME_TIME) {
      update();
      draw();
      InvalidateRect(hwnd, NULL, FALSE);
      lastTime += FRAME_TIME;
    }
  }

  return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  switch (uMsg) {
    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hwnd, &ps);

      BITMAPINFO bmi = {0};
      bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
      bmi.bmiHeader.biWidth = WIDTH;
      bmi.bmiHeader.biHeight = -HEIGHT;
      bmi.bmiHeader.biPlanes = 1;
      bmi.bmiHeader.biBitCount = 24; // RGB
      bmi.bmiHeader.biCompression = BI_RGB;

      StretchDIBits(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, 0, 0, WIDTH, HEIGHT, bitmap, &bmi, DIB_RGB_COLORS, SRCCOPY);

      EndPaint(hwnd, &ps);
    }
      return 0;
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
    default:
      return DefWindowProc(hwnd, uMsg, wParam, lParam);
  }
}
