#include "hitbox.h"
#include "../../assets/obj/object.h"

bool hitboxCollision(Hitbox box, Hitbox other) {
  return (box.x1 < other.x2 && box.x2 > other.x1 && box.y1 < other.y2 && box.y2 > other.y1);
}

Hitbox createHitbox(Object object, Vector2 size, Vector2 offset) {
  return (Hitbox) {
    object.position.x + offset.x,
    object.position.x + offset.x + size.x,
    object.position.y + offset.y,
    object.position.y + offset.y + size.y
  };
}
