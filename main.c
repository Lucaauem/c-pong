#include "./core/window.h"
#include "./core/graphics.h"
#include <windows.h>
#include "./assets/ball.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  return openWindow(hInstance, nCmdShow);
}

void draw(void) {
  resetFrame();
  drawSprite(ball);
}

void update(void) {
  ball_move();
}

