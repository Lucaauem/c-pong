#include "scene.h"
#include "../../core/graphics/renderer.h"
#include <stdlib.h>

void scene_render(Scene scene) {
  for(int i=0; i<scene.objectCount; i++) {
    render(*scene.objects[i]);
  }
}

void scene_addObject(Scene* scene, Object* object) {
  scene->objects = realloc(scene->objects, (scene->objectCount + 1) * sizeof(Object));
  scene->objects[scene->objectCount] = object;
  scene->objectCount++;
}

void scene_delete(Scene* scene) {
  free(scene->objects);
  scene->objects = NULL;
  scene->objectCount = 0;
}
