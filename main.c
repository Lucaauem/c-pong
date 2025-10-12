#include "./core/window.h"
#include "./core/graphics.h"
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

void draw() {
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

void update() {
  switch (gamestate) {
    case ROUND:
      updateGameRound();
      break;
  }
}

int main() {
  updateFunction = update;
  drawFunction = draw;
  setEvent_onDown(player_moveDown);
  setEvent_onUp(player_moveUp);

  createWindow();
  return 0;
}
