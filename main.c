#include "./core/window.h"
#include "./assets/ball.h"
#include "./assets/hitter.h"
#include "./assets/scenes/scene.h"
#include "./core/controller/controller.h"
#include "./core/graphics/renderer.h"
#include "core/graphics/texture.h"
#include "core/math.h"
#include <stdbool.h>

enum Gamestate {
  ROUND
};

struct Gamepoints {
  int player1;
  int player2;
};

const int goal_distance = 10;
enum Gamestate gamestate;
struct Gamepoints points;
Scene scene = { NULL, 0 };

void player_moveUp() { hitter_move(&hitter_1, -1); };
void player_moveDown() { hitter_move(&hitter_1, 1); };

void initGame() {
  gamestate = ROUND;
  points = (struct Gamepoints) {0, 0};

  scene_addObject(&scene, &ball);
  scene_addObject(&scene, &hitter_1.object);
  scene_addObject(&scene, &hitter_2.object);

  setEvent_onUp(player_moveUp);
  setEvent_onDown(player_moveDown);
}

void draw() {
  resetFrame();

  switch (gamestate) {
    case ROUND:
      scene_render(scene);
  }
}

void resetRound() {
  ball.position = (Vector2) { RESOLUTION_WIDTH / 2, RESOLUTION_HEIGHT / 2 };
  hitter_1.object.position.y = RESOLUTION_HEIGHT / 2;
  hitter_2.object.position.y = RESOLUTION_HEIGHT / 2;
}

void checkGoal() {
  if((ball.position.x > goal_distance) && (ball.position.x < (RESOLUTION_WIDTH - goal_distance))) {
    return;
  }

  if(ball.position.x < RESOLUTION_WIDTH / 2) {
    points.player1++;
  }
  if(ball.position.x > RESOLUTION_WIDTH / 2) {
    points.player2++;
  }

  resetRound();
}

void updateGameRound() {
  ball_checkCollision(hitter_1);
  ball_checkCollision(hitter_2);
  ball_move();
  checkGoal();

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
  ball.texture = readTexture("./ressources/sprites/test.bin");
  hitter_1.object.texture = readTexture("./ressources/sprites/hitter.bin");
  hitter_2.object.texture = readTexture("./ressources/sprites/hitter.bin");

  initGame();
  updateFunction = update;
  drawFunction = draw;

  createWindow();

  // Cleanup
  scene_delete(&scene);
  
  return 0;
}
