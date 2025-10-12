#pragma once

#include "../core/graphics/sprite.h"
#include "hitter.h"

extern Sprite ball;

void ball_move();
void ball_checkCollision(Hitter other);
