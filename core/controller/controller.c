#include "controller.h"
#include "SDL_keycode.h"
#include <SDL2/SDL.h>

void (*function_onDown)() = NULL;
void (*function_onUp)() = NULL;

void setEvent_onDown(void (*fp)()) { 
  function_onDown = fp;
}

void setEvent_onUp(void (*fp)()) {
  function_onUp = fp;
}

void setEvent_onLeft(void (*fp)()) {

}

void setEvent_onRight(void (*fp)()) {

}

void handleInput(SDL_KeyCode input) {
  switch (input) {
    case SDLK_w:
      if (function_onUp != NULL) {
        function_onUp();
      }
      break;
    case SDLK_s:
      if (function_onDown != NULL) {
        function_onDown();
      }
      break;
    default:
      break;
  }
}
