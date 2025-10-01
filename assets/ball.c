#include "./ball.h"
#include "../core/graphics.h"
#include "../core/math.h"

const float speed = 2.5f;

Vector2 ballAcc = {1, 1};
Sprite ball = {{WIDTH / 2, HEIGHT / 2}, 5, 5};

void ball_move() {

  ball.position.x += (int)(ballAcc.x * speed);
  ball.position.y += (int)(ballAcc.y * speed);

  if(ball.position.x >= WIDTH - ball.width) {
    ball.position.x = WIDTH - ball.width;
    ballAcc.x = -1;
  } else if(ball.position.x <= 0) {
    ball.position.x = 0;
    ballAcc.x = 1;
  }

  if(ball.position.y <= 0) {
    ball.position.y = 0;
    ballAcc.y = 1;
  } else if(ball.position.y >= HEIGHT - ball.height) {
    ball.position.y = HEIGHT - ball.height;
    ballAcc.y = -1;
  }
}
