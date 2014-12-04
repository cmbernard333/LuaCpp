#ifndef __SDL2_UTILITY_BEARDFISH__
#define __SDL2_UTILITY_BEARDFISH__
#include <iostream>
#include <ostream>
#include <SDL.h>
namespace beardfishplus {

    static inline void log_msg(std::ostream& stream, const std::string& msg="") {
        stream << msg.c_str() << std::endl;
    }

    static inline void log_msg(const std::string &msg="") {
        log_msg(std::cout,msg);
    }

	static inline void log_SDL_error(const char* msg) {
		std::cerr << "[Error -> " << msg << " ]: " << SDL_GetError() << std::endl;
	}
}
#endif
