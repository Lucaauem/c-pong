#include "renderer.h"
#include "./sprite.h"
#include "./texture.h"

unsigned char bitmap[RESOLUTION_WIDTH * RESOLUTION_HEIGHT * 3];

void render(Sprite* sprite) {
  for(int j=0; j<sprite->texture.height; j++) {
    for(int i=0; i<sprite->texture.width; i++) {
      if(sprite->texture.bitmap[j] & (1 << i)) {
        drawPixel(sprite->position.x + i, sprite->position.y + j, (Color){255, 255, 255});
      }
    }
  }
}

void resetFrame() {
  for(int i=0; i<(RESOLUTION_HEIGHT * RESOLUTION_WIDTH * 3); i++) {
    bitmap[i] = (unsigned char) 0;
  }
}

void drawPixel(int x, int y, Color color) {
  if(x<0 || x>=RESOLUTION_WIDTH || y<0 || y>= RESOLUTION_HEIGHT) { return; }

  int idx = (y * RESOLUTION_WIDTH + x) * 3;

  bitmap[idx + 0] = (unsigned char) color.blue;
  bitmap[idx + 1] = (unsigned char) color.green;
  bitmap[idx + 2] = (unsigned char) color.red;
}
