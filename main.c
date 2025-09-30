#include "window.h"
#include <windows.h>

typedef struct {
  int red;
  int green;
  int blue;
} Color;

typedef struct {
  int x;
  int y;
} Position;

Position pos = {0, 0};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
  return openWindow(hInstance, nCmdShow);
}

void drawPixel(Color color, int x, int y) {
  int idx = (y * WIDTH + x) * 3;

  bitmap[idx + 0] = (unsigned char)(color.blue);
  bitmap[idx + 1] = (unsigned char)(color.green);
  bitmap[idx + 2] = (unsigned char)(color.red);
}

void draw(void) {
  // Reset Frame
  for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
    bitmap[i] = (unsigned char)0;
  }

  Color pixel = {255, 255, 255};
  drawPixel(pixel, pos.x, HEIGHT / 2);
}

void update(void) { pos.x++; }
