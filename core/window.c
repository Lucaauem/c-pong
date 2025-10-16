#include "window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include "./controller/controller.h"
#include "./graphics/renderer.h"

void (*updateFunction)();
void (*drawFunction)();

void createWindow() {
  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("%s\n", SDL_GetError());
    exit(1);
  }

  SDL_Window *win = SDL_CreateWindow(
    "C-PONG",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    WIN_WIDTH,
    WIN_HEIGHT,
    SDL_WINDOW_SHOWN
  );

  if(win == NULL) {
    printf("%s\n", SDL_GetError());
    SDL_Quit();
    exit(1);
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STATIC, RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
  SDL_UpdateTexture(texture, NULL, bitmap, RESOLUTION_WIDTH * 3);

  Uint32 lastTime = SDL_GetTicks();
  float accumulator = 0;

  int running = 1;
  SDL_Event event;
  while(running) {
    // Handle DeltaTime
    Uint32 current = SDL_GetTicks();
    float dt = (current - lastTime) / 1000.0f;
    lastTime = current;
    accumulator += dt;

    while(SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = 0;
      }

      if (event.type == SDL_KEYDOWN) {
        if(event.key.keysym.sym == SDLK_ESCAPE) {
          running = 0;
          break;
        }
        handleInput(event.key.keysym.sym);
      }
    }

    static Uint32 lastDraw = 0;
    if(current - lastDraw >= FRAME_TIME) {
      updateFunction(); // TODO: Out of draw block and add DeltaTime
      drawFunction();

      SDL_UpdateTexture(texture, NULL, bitmap, RESOLUTION_WIDTH * 3);
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, texture, NULL, NULL);
      SDL_RenderPresent(renderer);
      
      lastDraw = current;
    }
  }

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
