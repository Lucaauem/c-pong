#pragma once

#include "./obj/object.h"
#include "../core/math.h"
#include <stdbool.h>

#define PADDING_TO_BORDER 25 

typedef struct {
  Object object;
  bool playerControlled;
} Hitter;

extern Hitter hitter_1;
extern Hitter hitter_2;

void hitter_move(Hitter* hitter, int direction);
void hitter_moveComputer(Hitter* hitter, Vector2 ballPosition);
