#include "renderer.h"

unsigned char bitmap[RESOLUTION_WIDTH * RESOLUTION_HEIGHT * 3];

void render(Object object) {
  Texture texture = object.texture;

  for(int j=0; j<texture.height; j++) {
    for(int i=0; i<texture.width; i++) {
      int pixelIndex = (j * texture.width + i) * texture.channels;

      Color pixelcolor = (Color) {
        (int) texture.bitmap[pixelIndex + 2],
        (int) texture.bitmap[pixelIndex + 1],
        (int) texture.bitmap[pixelIndex + 0]
      };

      // Skip pixel if texture sample is transparent
      if((texture.channels == 4) && (texture.bitmap[pixelIndex] + 3 == 0)) {
        continue;
      }

      drawPixel(object.position.x + i, object.position.y + j, pixelcolor);
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
