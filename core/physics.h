#pragma once

#include "./graphics/sprite.h"
#include <stdbool.h>

typedef struct {
  int x1;
  int x2;
  int y1;
  int y2;
} Hitbox;

bool hitboxCollision(Hitbox box, Hitbox other);
Hitbox createHitbox(Sprite sprite);
