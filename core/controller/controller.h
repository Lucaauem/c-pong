#pragma once

#include <SDL2/SDL_keycode.h>

void setEvent_onUp(void (*fp)());
void setEvent_onDown(void (*fp)());
void setEvent_onLeft(void (*fp)());
void setEvent_onRight(void (*fp)());
void handleInput(SDL_KeyCode input);
