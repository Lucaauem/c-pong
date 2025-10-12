#include "./core/window.h"
#include "./assets/ball.h"
#include "./assets/hitter.h"
#include "./core/controller/controller.h"
#include "./core/graphics/renderer.h"

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
      render(ball);
      render(hitter_1.sprite);
      render(hitter_2.sprite);
  }
}

void updateGameRound() {
  ball_checkCollision(hitter_1);
  ball_checkCollision(hitter_2);
  ball_move();

  hitter_moveComputer(&hitter_2, ball.position);
}

void update() {
  switch (gamestate) {
    case ROUND:
      updateGameRound();
      break;
  }
}

int main() {
  //ball.texture = readTexture("./test.bin"); // FIXME: Texture usage

  updateFunction = update;
  drawFunction = draw;
  setEvent_onDown(player_moveDown);
  setEvent_onUp(player_moveUp);

  createWindow();
  return 0;
}
