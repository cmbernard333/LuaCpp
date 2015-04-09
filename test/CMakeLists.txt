cmake_minimum_required(VERSION 3.0)
project(LuaCppTest)
set ( SRC_DIR ${LuaCppTest}/src )
# define directories
set(SRC_DIR ${LuaCppTest_SOURCE_DIR}/src)
# set the compiler flags based on compiler
if (APPLE OR CMAKE_SYSTEM_NAME STREQUAL Linux)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m64 -fno-exceptions -fno-rtti -fPIC -fno-omit-frame-pointer -momit-leaf-frame-pointer")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# grab LuaCpp include directory 
include_directories(${LuaCppLib_SOURCE_DIR}/include)
# grab the local directory
include_directories(${LuaCppTest_SOURCE_DIR}/include)
# grab the lua directory
include_directories(${LUA_PATH})
# glob the headers from the local one
file(GLOB LuaCppTest_HEADERS ${LuaCppTest_SOURCE_DIR}/include/*/*.h*)
source_group("Headers" FILES ${LuaCppTest_HEADERS})
# generate the executable 
add_executable(LuaCppTest ${SRC_DIR}/luaStateTest.cpp ${LuaCppTest_HEADERS})
# link the library
target_link_libraries(LuaCppTest LuaCppLib ${LUA_PATH}/liblua.a) 
