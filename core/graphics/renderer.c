#include "renderer.h"
#include "./sprite.h"
#include "./texture.h"

unsigned char bitmap[RESOLUTION_WIDTH * RESOLUTION_HEIGHT * 3];

void render(Sprite sprite) {
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      drawPixel(sprite.position.x + i, sprite.position.y + j, (Color) {255, 255, 255});
    }
  }

  return;
  // TODO: Texture handling
  //
  for(int i=0; i<sprite.texture.width; i++) {
    for(int j=0; i<sprite.texture.height; j++) {
      // TODO: Only draw when bit is 0

      int pixelX = sprite.position.x + i;
      int pixelY = sprite.position.y + j;
      drawPixel(pixelX, pixelY, sprite.texture.color);
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
