#include "./ball.h"
#include "../core/math.h"
#include "hitter.h"
#include "../core/physics/hitbox.h"
#include "../core/graphics/renderer.h"

const float speed = 2.5f;
const int ball_size = 3;

Vector2 ballAcc = {1, 1};
Object ball = { { RESOLUTION_WIDTH / 2, RESOLUTION_HEIGHT / 2}, {}, {} };

void ball_move() {
  ball.position.x += (int)(ballAcc.x * speed);
  ball.position.y += (int)(ballAcc.y * speed);

  if(ball.position.x >= RESOLUTION_WIDTH - ball.texture.width) {
    ball.position.x = RESOLUTION_WIDTH - ball.texture.width;
    ballAcc.x = -1;
  } else if(ball.position.x <= 0) {
    ball.position.x = 0;
    ballAcc.x = 1;
  }

  if(ball.position.y <= 0) {
    ball.position.y = 0;
    ballAcc.y = 1;
  } else if(ball.position.y >= RESOLUTION_HEIGHT - ball.texture.height) {
    ball.position.y = RESOLUTION_HEIGHT - ball.texture.height;
    ballAcc.y = -1;
  }
}

// TODO: Check edge cases when colliding
void ball_checkCollision(Hitter other) {
  Hitbox hitterHitbox = createHitbox(other.object, (Vector2){2,20}, (Vector2){2,0});
  Hitbox ballHitbox = createHitbox(ball, (Vector2){4,4}, (Vector2){0,0});

  if (!hitboxCollision(hitterHitbox, ballHitbox)) {
    return;
  }

  ballAcc.x = (-1) * ballAcc.x;
}
