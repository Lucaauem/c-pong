#include "hitter.h"
#include "../core/math.h"
#include "../core/graphics.h"
#include "../core/math.h"

const float hitter_speed = 3.0f;
const int hitter_height = 5;
const int hitter_width = 2;

Hitter hitter_1 = {
  { { 50, HEIGHT / 2 }, hitter_width, hitter_height }, 
  false
};

void hitter_move(Hitter* hitter, int direction) {
  hitter->sprite.position.y += (int)(hitter_speed * direction);

  // TODO: Fix repositioning
  if(hitter->sprite.position.y >= HEIGHT) {
    hitter->sprite.position.y = HEIGHT;
  } else if(hitter->sprite.position.y <= 0) {
    hitter->sprite.position.y = hitter->sprite.height;
  }
}
