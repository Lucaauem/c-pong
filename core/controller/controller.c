#include "controller.h"
#include <stdio.h>
#include <ctype.h>
#include <stdio.h>

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

void handleInput(char c) {
  char input = tolower(c);

  switch (input) {
    case 'w':
      if (function_onUp != NULL) {
        function_onUp();
      }
      break;
    case 's':
      if (function_onDown != NULL) {
        function_onDown();
      }
      break;
  }
}
