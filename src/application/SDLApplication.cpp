#include <SDL.h>
#include "application/SDLApplication.h"
#include "utility/LogUtility.h"
namespace beardfishplus {

int SDL_OK = 0;
int SDL_INIT_FAILURE = 1;
int SDL_RENDERER_FAILURE = 2;
int SDL_WINDOW_FAILURE = 3;

SDLApplication::~SDLApplication() {
  SAFE_DESTROY_RENDERER(this->ren);
  SAFE_DESTROY_WINDOW(this->win);
  SDL_Quit();
  log_msg("Quitting SDL...");
}

int SDLApplication::init(Uint32 args) {
  if (SDL_Init(args) != 0) {
    log_SDL_error("SDL_Init");
    return SDL_INIT_FAILURE;
  }
  this->win =
      SDL_CreateWindow("Beardfish", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  if (win == nullptr) {
    log_SDL_error("SDL_CreateWindow");
    return SDL_WINDOW_FAILURE;
  }
  this->ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
  if (ren == nullptr) {
    log_SDL_error("SDL_CreateRenderer");
    return SDL_RENDERER_FAILURE;
  }
  return SDL_OK;
}

void SDLApplication::run() {
  SDL_RenderClear(this->ren);
  SDL_RenderPresent(this->ren);
  SDL_Delay(2000);
}
}
