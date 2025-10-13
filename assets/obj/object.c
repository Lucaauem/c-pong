#include "object.h"

bool object_colliding(Object object, Object other) {
  return hitboxCollision(object.hitbox, other.hitbox);
}

void object_move(Object* object, Vector2 direction) {
  // Update position
  object->position.x += direction.x;
  object->position.y += direction.y;

  // Update hitbox
  object->hitbox = object_createHitbox(*object);
}

Hitbox object_createHitbox(Object object) {
  return (Hitbox) {
    object.position.x,
    object.position.x + 1,
    object.position.y,
    object.position.y + 1
  };
}
