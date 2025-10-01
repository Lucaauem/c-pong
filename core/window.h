#pragma once

#include <windows.h>

#define WIDTH 256
#define HEIGHT 240
#define WIN_WIDTH 1024
#define WIN_HEIGHT 960
#define TARGET_FPS 30
#define FRAME_TIME 1000 / TARGET_FPS

extern unsigned char bitmap[WIDTH * HEIGHT * 3];

int openWindow(HINSTANCE hInstance, int nCmdShow);
void draw(void);
void update(void);
