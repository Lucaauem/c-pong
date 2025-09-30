#pragma once

#include "./math.h"
#include "./graphics.h"
#include "./window.h"

#define SPRITE_HEIGHT 8
#define SPRITE_WIDTH 8

typedef struct {
  int red;
  int green;
  int blue;
} Color;

typedef struct {
  Vector2 position;
} Sprite;

void resetFrame();
void drawPixel(int x, int y, Color color);
void drawSprite(Sprite sprite);

