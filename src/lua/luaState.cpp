#include "lua/luaState.h"
#include <iostream>

// ctor
LuaState::LuaState() {
  this->L = luaL_newstate();
  luaL_openlibs(this->L);
}


// dtor
LuaState::~LuaState() {
  lua_close(this->L);
}

/* register a function to the lua state */
void LuaState::registerCFunc(const std::string name, lua_CFunction func) {
  lua_register(this->L,name.c_str(),func);
}

/* register a table of functions to the lua state */
int LuaState::registerCFuncs(luaL_Reg funcs[]) {
    luaL_newlib(this->L,funcs);
    return 1;
}

/* load a file */
void LuaState::loadFile(const std::string file) {
  luaL_loadfile(this->L,file.c_str());
}

/* run a lua file */
void LuaState::doFile(const std::string file) {
  luaL_dofile(this->L,file.c_str());
}

/* dump the current lua stack */
void LuaState::stackDump(ostream *stream=std::cout) {
}
