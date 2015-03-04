#ifndef __LUA_C_FUNCTION_H__
#define __LUA_C_FUNCTION_H__
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

/* arguments are passed on the stack of the lua state */
/* lua_gettop() gets the top of the stack ( starts 1 )*/
/* this function returns an int indicating the number of results of the function
 */
/* return results need to be stored on the lua_state stack */
typedef int (*lua_CFunction)(lua_State *L);
#endif // __LUA_C_FUNCTION_H__
