-- A solution contians project, and defines the available configurations
solution "LuaCpp"
    configurations { "Debug", "Release" }
    -- A project defines one build target
    project "LuaCpp"
        -- define where lua is -- MODIFY THIS
        luapath = "./third_party/lua-5.2.3/src"
        sdl_include_path = "./third_party/SDL2-2.0.3/include"
        sdl_lib_path = "./third_party/SDL2-2.0.3/build/.libs"
        kind "ConsoleApp"
        language "C++"
        files {  "src/**.cpp" }
        -- the output location
        location "build"
        -- includes 
        includedirs { "include", luapath, sdl_include_path }
        -- linking
        libdirs { luapath, sdl_lib_path } 
        links { "lua", "SDL2" }
        -- place where sources are
        files { "src/*.cpp" }

        configuration "Debug"
            defines { "DEBUG " }
            flags { "Symbols" }

        configuration "Release"
            flags { "Optimize" }
