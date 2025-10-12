#include "hitter.h"
#include "../core/math.h"
#include "../core/graphics.h"

const float hitter_speed = 3.0f;
const int hitter_height = 30;
const int hitter_width = 4;

Hitter hitter_1 = {
  { { PADDING_TO_BORDER, HEIGHT / 2 }, hitter_width, hitter_height }, 
  false
};

Hitter hitter_2 = {
  { { WIDTH - PADDING_TO_BORDER, HEIGHT / 2 }, hitter_width, hitter_height  },
  false
};

void hitter_move(Hitter* hitter, int direction) {
  hitter->sprite.position.y += (int)(hitter_speed * direction);

  // TODO: Fix repositioning
  if(hitter->sprite.position.y + hitter_height >= HEIGHT) {
    hitter->sprite.position.y = HEIGHT - hitter_height;
  } else if(hitter->sprite.position.y <= 0) {
    hitter->sprite.position.y = 0;
  }
}

void hitter_moveComputer(Hitter* hitter, Vector2 ballPosition) {
  int centerPosY = hitter->sprite.position.y + (hitter_height / 2);
  int targetDirection = ballPosition.y > centerPosY ? 1 : -1;

  hitter_move(hitter, targetDirection);
}
