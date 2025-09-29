#pragma once

#include <windows.h>

#define WIDTH 480
#define HEIGHT 240

extern unsigned char bitmap[WIDTH * HEIGHT * 3];

int openWindow(HINSTANCE hInstance, int nCmdShow);
void draw(void);
