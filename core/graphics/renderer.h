#pragma once

#include "./sprite.h"
#include "./texture.h"

#define RESOLUTION_WIDTH 256
#define RESOLUTION_HEIGHT 240

extern unsigned char bitmap[RESOLUTION_WIDTH * RESOLUTION_HEIGHT * 3];

void render(Sprite sprite);
void resetFrame();
void drawPixel(int x, int y, Color color);
