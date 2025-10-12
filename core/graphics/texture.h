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
  Color color;
} Texture;

Texture readTexture(char path[]);
