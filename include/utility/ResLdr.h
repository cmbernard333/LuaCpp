#ifndef __RES_LDR_H__
#define __RES_LDR_H__
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "utility/LogUtility.h"
namespace beardfishplus {
    std::string getResourcePath(const std::string &subDir="") {
#ifdef _WIN32
        const char PATH_SEP = '\\';
#else
        const char PATH_SEP = '/';
#endif
        // only load up once and stay in memory
        static std::string baseRes;
        if(baseRes.empty()) {
            char *basePath = SDL_GetBasePath();
            if(basePath) {
                baseRes = basePath;
                SDL_free(basePath);
            } else {
                log_SDL_error("Error getting resource path!");
                return "";
            }
            // replace bin with res to get resource path
            size_t pos = baseRes.rfind("bin");
            baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
        }
        return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;
    }
}
#endif
