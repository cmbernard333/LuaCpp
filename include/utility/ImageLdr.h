/*
 * ImageLdr.h
 *
 *  Created on: Oct 2, 2014
 *      Author: christian
 */
#ifndef __IMAGE_LOADER__
#define __IMAGE_LOADER__
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "utility/LogUtility.h"
namespace beardfish {
	/* loads a texture from a file
	 * @param file = absolute path to a resource file
	 * @param ren = pointer to an SDL renderer
	 * @return SDL_Texture or nullptr
	 */
	SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren) {
		SDL_Texture *texture = IMG_LoadTexture(ren,file.c_str());
		if(texture==nullptr) {
			SDL_log_error("Error loading texture from file "+file.c_str());
		}
		return texture;
	}
}
#endif




