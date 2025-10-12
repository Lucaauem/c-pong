#pragma once

#include <SDL2/SDL.h>
#include "./graphics/renderer.h"

#define WIN_WIDTH 1024
#define WIN_HEIGHT 960
#define TARGET_FPS 30
#define FRAME_TIME 1000 / TARGET_FPS

extern void (*updateFunction)();
extern void (*drawFunction)();

void createWindow();
