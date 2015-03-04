-- A solution contians project, and defines the available configurations
solution "LuaCpp"
    configurations { "Debug", "Release" }
    -- A project defines one build target
    project "LuaCpp"
        -- define where lua is -- MODIFY THIS
        luapath = "./third_party/lua-5.2.3/src"
        kind "ConsoleApp"
        language "C++"
        -- place where sources are
        files {  "src/**.cpp" }
        -- the output location
        location "build"
        -- includes 
        includedirs { "include", luapath }
        -- linking
        libdirs { luapath } 
        links { "lua" }

        configuration "Debug"
            defines { "DEBUG " }
            flags { "Symbols" }

        configuration "Release"
            flags { "Optimize" }
