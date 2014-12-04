#ifndef __LUA_STATE_H__
#define __LUA_STATE_H__
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "luacfunc.h"
#include <string>

/* 
 * TODO: abstract LuaState machine into C++ object
 */

class LuaState {
    public :
        LuaState();
        virtual ~LuaState();
        void registerFunc(const std::string name, lua_CFunction func);
        void loadFile(const std::string name);
        void doFile(const std::string name);

    private:
        lua_State* L;
};

#endif
