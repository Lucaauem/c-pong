#pragma once

#include "../math.h"
#include <stdbool.h>

typedef struct Object Object;

typedef struct Hitbox {
  int x1;
  int x2;
  int y1;
  int y2;
} Hitbox;

bool hitboxCollision(Hitbox box, Hitbox other);
Hitbox createHitbox(Object object, Vector2 size, Vector2 offset);
