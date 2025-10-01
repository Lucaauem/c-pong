#pragma once

void setEvent_onUp(void (*fp)());
void setEvent_onDown(void (*fp)());
void setEvent_onLeft(void (*fp)());
void setEvent_onRight(void (*fp)());
void handleInput(char c);
