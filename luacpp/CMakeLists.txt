cmake_minimum_required(VERSION 3.0)
project(LuaCppLib)
set ( LuaCppLib_VERSION_MAJOR 1 )
set ( LuaCppLib_VERSION_MINOR 0 )
# set ( CMAKE_VERBOSE_MAKEFILE on )

# third_party directory
if (NOT DEFINED LUA_PATH )
    set( LUA_PATH ${LuaCppLib_SOURCE_DIR}../third_party/lua-5.2.3/src )
endif()

# define directories
set(SRC_DIR ${LuaCppLib_SOURCE_DIR}/src)
# set the compiler flags based on compiler
if (APPLE OR CMAKE_SYSTEM_NAME STREQUAL Linux)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m64 -fno-exceptions -fno-rtti -fPIC -fno-omit-frame-pointer -momit-leaf-frame-pointer")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
    if(APPLE)
        set(CMAKE_SHARED_LINKER_FLAGS "-undefined dynamic_lookup")
    else()
        set(CMAKE_SHARED_LINKER_FLAGS "-shared")
    endif()
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# grab local includes
include_directories(${LuaCppLib_SOURCE_DIR}/include)
# grab lua includes
include_directories(${LUA_PATH})
file(GLOB LuaCppLibHeaders ${LuaCppLib_SOURCE_DIR}/include/*/*.h*)
source_group("Headers" FILES ${LuaCppLibHeaders})
# generate the library 
add_library(LuaCppLib SHARED ${SRC_DIR}/lua/luaState.cpp)
# TODO: install to bin dir

