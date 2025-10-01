#include "physics.h"
#include "graphics.h"
#include <stdbool.h>

bool hitboxCollision(Hitbox box, Hitbox other) {
  return (box.x1 < other.x2 && box.x2 > other.x1 && box.y1 < other.y2 && box.y2 > other.y1);
}

Hitbox createHitbox(Sprite sprite) {
  return (Hitbox) {
    sprite.position.x,
    sprite.position.x + sprite.width,
    sprite.position.y,
    sprite.position.y + sprite.height
  };
}
