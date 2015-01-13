#ifndef __SDL_APPLICATION_HEADER__
#define __SDL_APPLICATION_HEADER__
#include <SDL.h>
namespace beardfishplus {
#define SAFE_DESTROY_RENDERER(renderer)                                        \
  if (renderer != nullptr)                                                     \
  SDL_DestroyRenderer(renderer)
#define SAFE_DESTROY_WINDOW(window)                                            \
  if (window != nullptr)                                                       \
  SDL_DestroyWindow(window)
#define SDL_OK 0;
#define SDL_INIT_FAILURE 1;
#define SDL_RENDERER_FAILURE 2;
#define SDL_WINDOW_FAILURE 3;

class SDLApplication {
public:
  virtual ~SDLApplication();
  int init(Uint32 args = SDL_INIT_EVERYTHING);
  void run();

private:
  SDL_Window *win;
  SDL_Renderer *ren;
};
}
#endif
