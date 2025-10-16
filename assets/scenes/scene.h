#pragma once

#include "../obj/object.h"

typedef struct Scene {
  Object** objects;
  int objectCount;
} Scene;

void scene_render(Scene scene);
void scene_addObject(Scene*, Object* object);
void scene_delete(Scene* scene);
