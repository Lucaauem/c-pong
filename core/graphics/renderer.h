#pragma once

#include "./texture.h"
#include "../../assets/obj/object.h"

#define RESOLUTION_WIDTH 256
#define RESOLUTION_HEIGHT 240

extern unsigned char bitmap[RESOLUTION_WIDTH * RESOLUTION_HEIGHT * 3];

void render(Object object);
void resetFrame();
void drawPixel(int x, int y, Color color);
