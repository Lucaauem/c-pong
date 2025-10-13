#include "texture.h"
#include <stdio.h>
#include <stdlib.h>

Texture readTexture(char path[]) {
  Color color = {255, 255, 255}; // TODO: Include real color handling
  FILE *file = fopen(path, "rb");

  if (file == NULL) {
    exit(1);
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  unsigned char *buffer = (unsigned char *)malloc(size);
  fread(buffer, 1, size, file);

  fclose(file);

  // TODO: Size of Texture
  return (Texture){buffer, 8, size, color};
}
