extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <string>
#include "luacfunc.h"

/* 
 * TODO: abstract LuaState machine into C++ object
 */

class LuaState {
    public :
        LuaState();
        virtual ~LuaState();
        int openLib(string* lib);
        int registerFunc(string *name, lua_CFunction func);
        int doFile(string *name);

    private:
        lua_State* L;
}
