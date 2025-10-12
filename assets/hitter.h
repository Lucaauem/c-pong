#pragma once

#include "../core/graphics/sprite.h"
#include "../core/math.h"
#include <stdbool.h>

#define PADDING_TO_BORDER 25 

typedef struct {
  Sprite sprite;
  bool playerControlled;
} Hitter;

extern Hitter hitter_1;
extern Hitter hitter_2;

void hitter_move(Hitter* hitter, int direction);
void hitter_moveComputer(Hitter* hitter, Vector2 ballPosition);
