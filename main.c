#include "./core/window.h"
#include "./core/graphics.h"
#include "./core/math.h"
#include <windows.h>

Sprite sprite = { {0,0} };

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  return openWindow(hInstance, nCmdShow);
}

void draw(void) {
  resetFrame();
  drawSprite(sprite);
}

void update(void) { sprite.position.x++; }

