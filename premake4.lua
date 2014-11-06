-- A solution contians project, and defines the available configurations
solution "LuaCpp"
    configurations { "Debug", "Release" }
    -- A project defines one build target
    project "LuaCpp"
        -- define where lua is -- MODIFY THIS
        luapath = "/Users/christian/Documents/Code/lua-5.2.3/src"
        kind "SharedLib"
        language "C++"
        files { "**.h", "**.cpp" }
        -- the output location
        location "build"
        -- includes 
        includedirs { "include", luapath }
        -- linking
        libdirs { luapath } 
        links { "lua" }
        -- place where sources are
        files { "src/*.cpp" }

        configuration "Debug"
            defines { "DEBUG " }
            flags { "Symbols" }

        configuration "Release"
            flags { "Optimize" }
