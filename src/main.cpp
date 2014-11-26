#include "luaState.h"
#include <iostream>
#include <cstdlib>

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
    LuaState L;
    /* register our function */
    L.registerFunc("average",average);
    /* run the script */
    L.doFile("lua/avg.lua");
    /* press enter to exit */
    std::cout<<"Press enter to exit...";
    getchar();
    return 0;
}
