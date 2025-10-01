#pragma once

#include "../core/graphics.h"
#include <stdbool.h>

typedef struct {
  Sprite sprite;
  bool playerControlled;
} Hitter;

extern Hitter hitter_1;

void hitter_move(Hitter* hitter, int direction);
