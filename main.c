#include "./core/window.h"
#include "./core/graphics.h"
#include <windows.h>
#include "./assets/ball.h"
#include "./assets/hitter.h"
#include "./core/controller/controller.h"

void player_moveUp() {
  hitter_move(&hitter_1, -1);
}

void player_moveDown() {
  hitter_move(&hitter_1, 1);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  setEvent_onUp(player_moveUp);
  setEvent_onDown(player_moveDown);

  return openWindow(hInstance, nCmdShow);
}

void draw(void) {
  resetFrame();
  drawSprite(ball);
  drawSprite(hitter_1.sprite);
}

void update(void) {
  ball_move();
}

