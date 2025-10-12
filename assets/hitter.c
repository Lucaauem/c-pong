#include "hitter.h"
#include "../core/math.h"
#include "../core/graphics/sprite.h"
#include "../core/graphics/renderer.h"

const float hitter_speed = 3.0f;
const int hitter_height = 30;
const int hitter_width = 4;

Hitter hitter_1 = { { {}, { PADDING_TO_BORDER, RESOLUTION_HEIGHT / 2} }, true }; // TODO:
Hitter hitter_2 = { { {}, { RESOLUTION_WIDTH - PADDING_TO_BORDER, RESOLUTION_HEIGHT / 2} }, false}; // TODO:

void hitter_move(Hitter* hitter, int direction) {
  hitter->sprite.position.y += (int)(hitter_speed * direction);

  if(hitter->sprite.position.y + hitter_height >= RESOLUTION_HEIGHT) {
    hitter->sprite.position.y = RESOLUTION_HEIGHT - hitter_height;
  } else if(hitter->sprite.position.y <= 0) {
    hitter->sprite.position.y = 0;
  }
}

void hitter_moveComputer(Hitter* hitter, Vector2 ballPosition) {
  int centerPosY = hitter->sprite.position.y + (hitter_height / 2);
  int targetDirection = ballPosition.y > centerPosY ? 1 : -1;

  hitter_move(hitter, targetDirection);
}
