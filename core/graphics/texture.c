#define STB_IMAGE_IMPLEMENTATION
#include "../../libs/stb_image.h"
#include "texture.h"

Texture texture_load(char path[]) {
  int width;
  int height;
  int channels;

  unsigned char* bitmap = stbi_load(path, &width, &height, &channels, 0);

  return (Texture) {bitmap, width, height, channels};
}

void texture_clear(Texture* texture) {
  stbi_image_free(texture->bitmap);
  texture->bitmap = NULL;
}
