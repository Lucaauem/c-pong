#include "./core/window.h"
#include "./core/graphics.h"
#include <windows.h>
#include "./assets/ball.h"
#include "./assets/hitter.h"
#include "./core/controller/controller.h"

enum Gamestate {
  ROUND
};

enum Gamestate gamestate = ROUND;

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

  switch (gamestate) {
    case ROUND:
      drawSprite(ball);
      drawSprite(hitter_1.sprite);
  }
}

void updateGameRound() {
  ball_checkCollision(hitter_1);
  ball_move();
}

void update(void) {
  switch (gamestate) {
    case ROUND:
      updateGameRound();
      break;
  }
}

