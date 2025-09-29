#include "window.h"
#include <windows.h>

void draw(void) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int idx = (y * WIDTH + x) * 3;
      bitmap[idx + 0] = (unsigned char)(x % 256);
      bitmap[idx + 1] = (unsigned char)(y % 256);
      bitmap[idx + 2] = 128;
    }
  }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
  return openWindow(hInstance, nCmdShow);
}
