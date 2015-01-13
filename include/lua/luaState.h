#ifndef __LUA_STATE_H__
#define __LUA_STATE_H__
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "luacfunc.h"
#include <string>
#include <cassert>
#include <cstdlib>
#include <iostream>
/* check to see if its lua 5.1 */
#ifndef luaL_newlib 
#define LUA_VN "lua51"
#define luaL_newlib(L,l) (lua_newtable(L), luaL_register(L,NULL,l))
#define luaL_setfuncs(L,l,n) (assert(n==0), luaL_register(L,NULL,l))
#else
#define LUA_VN "lua52"
#endif

/* 
 * TODO: abstract LuaState machine into C++ object
 */

class LuaState {
    public :
        LuaState();
        virtual ~LuaState();
        void registerCFunc(const std::string name, lua_CFunction func);
        int registerCFuncs(luaL_Reg funcs []);
        void loadFile(const std::string name);
        void doFile(const std::string name);
        void dumpStack(const ostream *stream);

    private:
        lua_State* L;
};

#endif
