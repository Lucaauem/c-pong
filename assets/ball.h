#pragma once

#include "./obj/object.h"
#include "hitter.h"

extern Object ball;

void ball_move();
void ball_checkCollision(Hitter other);
