#pragma once

#include "../../core/math.h"
#include "../../core/graphics/texture.h"
#include "../../core/physics/hitbox.h"
#include <stdbool.h>

typedef struct Object {
  Vector2 position;
  Hitbox hitbox;
  Texture texture;
} Object;

bool object_colliding(Object object, Object other);
void object_move(Object* object, Vector2 direction);
Hitbox object_createHitbox(Object object);
