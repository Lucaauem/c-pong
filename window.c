#include "window.h"
#include <iso646.h>
#include <windows.h>

unsigned char bitmap[WIDTH * HEIGHT * 3];

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int openWindow(HINSTANCE hInstance, int nCmdShow) {
  const char CLASS_NAME[] = "pongWindow";

  WNDCLASS wc = {0};
  wc.lpfnWndProc = WindowProc;
  wc.hInstance = hInstance;
  wc.lpszClassName = CLASS_NAME;

  RegisterClass(&wc);

  HWND hwnd = CreateWindowEx(0, CLASS_NAME, "C-Pong", WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, CW_USEDEFAULT, HEIGHT, WIDTH, NULL,
                             NULL, hInstance, NULL);

  if (hwnd == NULL)
    return 0;

  ShowWindow(hwnd, nCmdShow);

  MSG msg = {0};
  while (GetMessage(&msg, NULL, 0, 0)) {
    PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
    if (msg.message == WM_QUIT)
      break;
    TranslateMessage(&msg);
    DispatchMessage(&msg);

    update();

    draw();
  }

  return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                            LPARAM lParam) {
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

    StretchDIBits(hdc, 0, 0, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, bitmap, &bmi,
                  DIB_RGB_COLORS, SRCCOPY);

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
