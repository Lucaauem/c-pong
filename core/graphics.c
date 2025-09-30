#include "./graphics.h"
#include "./window.h"

void resetFrame() {
  for(int i=0; i<(HEIGHT*WIDTH*3); i++) {
    bitmap[i] = (unsigned char) 0;
  }
}

void drawPixel(int x, int y, Color color) {
  int idx = (y * WIDTH + x) * 3;

  bitmap[idx + 0] = (unsigned char) color.blue;
  bitmap[idx + 1] = (unsigned char) color.green;
  bitmap[idx + 2] = (unsigned char) color.red;
}

void drawSprite(Sprite sprite) {
  Color color = {255, 255, 255};
  drawPixel(sprite.position.x, sprite.position.y, color);
}
