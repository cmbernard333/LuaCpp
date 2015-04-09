#include "lua/luaState.h"
#include <iostream>

// ctor
LuaState::LuaState() {
  this->L = luaL_newstate();
  luaL_openlibs(this->L);
}

// dtor
LuaState::~LuaState() { lua_close(this->L); }

/* register a function to the lua state */
void LuaState::registerCFunc(const std::string name, lua_CFunction func) {
  lua_register(this->L, name.c_str(), func);
}

/* register a table of functions to the lua state */
void LuaState::registerCLib(luaL_Reg funcs[]) {
  lua_newtable(L);
  luaL_setfuncs(L, funcs, 0);
  /* push another named table */
  lua_pushvalue(L, -1);
}

/* load a file */
void LuaState::loadFile(const std::string file) {
  luaL_loadfile(this->L, file.c_str());
}

/* run a lua file */
void LuaState::doFile(const std::string file) {
  luaL_dofile(this->L, file.c_str());
}

/* dump the current lua stack */
void LuaState::stackDump(std::ostream &stream) const {
  int top = lua_gettop(this->L);
  stream << "stack depth: " << top << std::endl;
  for (int i = 1; i <= top; i++) {
    int t = lua_type(this->L, i);
    printLuaType(this->L, t, i, stream);
    stream << " ";
  }
  stream << std::endl;
}

/* trace the stack in lua */
void LuaState::stackTrace(std::ostream &stream) const {
  lua_Debug entry;
  int depth = 0;
  while (lua_getstack(this->L, depth, &entry)) {
    int status = lua_getinfo(L, "Sln", &entry);
    assert(status);

    stream << entry.short_src << "(" << entry.currentline << ")"
           << entry.currentline << ":" << (entry.name ? entry.name : "?")
           << std::endl;
    depth++;
  }
}

/* helper function for printing types */
void LuaState::printLuaType(lua_State *L, int type, int index,
                            std::ostream &stream) const {
  switch (type) {
  case LUA_TSTRING:
    stream << "string: " << lua_tostring(L, index);
    break;
  case LUA_TBOOLEAN:
    stream << "boolean: " << lua_toboolean(L, index) ? "true" : "false ";
    break;
  case LUA_TNUMBER:
    stream << "number: " << lua_tonumber(L, index);
    break;
  case LUA_TTABLE:
    /* call print table from here */
    break;
  default:
    stream << "user type:" << lua_typename(L, index);
    break;
  }
}

/* print the contents of a table */
void LuaState::printTable(lua_State *L, std::ostream &stream) const {
	lua_pushnil(L);

	while(lua_next(L,-2) != 0) {
		if(lua_istable(L,-1)) {
			printTable(L,stream);
		} else {
			printLuaType(L,lua_type(L,-2),-2,stream);
			stream << " = ";
			printLuaType(L,lua_type(L,-1),-1,stream);
		}

		lua_pop(L,1);
	}
}
