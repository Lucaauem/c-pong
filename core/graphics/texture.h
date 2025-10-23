#pragma once

typedef struct {
  int red;
  int green;
  int blue;
} Color;

typedef struct {
  unsigned char* bitmap;
  unsigned int width;
  unsigned int height;
  unsigned int channels;
} Texture;

Texture texture_load(char path[]);
void texture_clear(Texture* texture);
