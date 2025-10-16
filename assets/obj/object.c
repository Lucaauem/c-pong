#include "object.h"

bool object_colliding(Object object, Object other) {
  return hitboxCollision(object.hitbox, other.hitbox);
}

void object_move(Object* object, Vector2 direction) {
  // Update position
  object->position.x += direction.x;
  object->position.y += direction.y;

  // Update hitbox
  object->hitbox.x1 += direction.x;
  object->hitbox.x2 += direction.x;
  object->hitbox.y1 += direction.y;
  object->hitbox.y2 += direction.y;
}
