#include "hitbox.h"
#include "../../assets/obj/object.h"
#include <stdbool.h>

bool hitboxCollision(Hitbox box, Hitbox other) {
  return (box.x1 < other.x2 && box.x2 > other.x1 && box.y1 < other.y2 && box.y2 > other.y1);
}

Hitbox createHitbox(Object object) {
  return (Hitbox) {
    object.position.x,
    object.position.x + object.texture.width,
    object.position.y,
    object.position.y + object.texture.height
  };
}
