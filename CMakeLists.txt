cmake_minimum_required(VERSION 3.0)
project(LuaCpp)
set ( LuaCpp_VERSION_MAJOR 1 )
set ( LuaCpp_VERSION_MINOR 0 )
set ( CMAKE_VERBOSE_MAKEFILE on )

# third_party directory
set( LUA_PATH ${LuaCpp_SOURCE_DIR}/third_party/lua-5.2.3/src )

add_subdirectory(luacpp)
add_subdirectory(test)
