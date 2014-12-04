#ifndef __SDL_APPLICATION_HEADER__
#define __SDL_APPLICATION_HEADER__
#include <SDL.h>
namespace beardfishplus {
#define SAFE_DESTROY_RENDERER(renderer) if(renderer!=nullptr) SDL_DestroyRenderer(renderer)
#define SAFE_DESTROY_WINDOW(window) if(window!=nullptr) SDL_DestroyWindow(window)
	extern int SDL_OK;
	extern int SDL_INIT_FAILURE;
    extern int SDL_RENDERER_FAILURE;
    extern int SDL_WINDOW_FAILURE;
	
    class SDLApplication {
        public:
            virtual ~SDLApplication();
            int init(Uint32 args = SDL_INIT_EVERYTHING);
            void run();
        private :
            SDL_Window *win;
            SDL_Renderer *ren;
    };
}
#endif
