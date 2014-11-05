#include "luacfunc.h"
#include <cstdlib>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

static int average(lua_State *L) {
    /* get the number of arguments */
    int n = lua_gettop(L);

    /* loop through each argument and add to sum */
    double sum = 0;
    int i = 0;
    for(i = 1; i<=n; i++) {
        /* grab the element on the stack and sum it */
        sum += lua_tonumber(L,i);
    }

    /* push the average to the lua state */
    lua_pushnumber(L,sum/n);
    /* push the sum */
    lua_pushnumber(L,sum);

    return 2; 
}

/* initially all the loading is done before calling lua*/
/* anything loaded into the lua state can be accessed in lua land */
int main(int argc, char** argv) {
    /* TODO : abstract lua state into object*/
    lua_State *L = luaL_newstate(); 
    /* base libs */
    luaL_openlibs(L);
    /* register our function */
    lua_register(L,"average",average);
    /* run the script */
    luaL_dofile(L,"avg.lua");
    /* cleanup lua */
    lua_close(L);
    /* press enter to exit */
    printf("Press enter to exit...");
    getchar();
    return 0;
}
