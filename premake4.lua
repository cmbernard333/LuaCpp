-- A solution contians project, and defines the available configurations
solution "LuaCpp"
    print("Building for "..os.get())
    configurations { "Debug", "Release" }
    -- define where lua is -- MODIFY THIS
    luapath = "./third_party/lua-5.2.3/src"
    -- A project defines one build target
    project "LuaCpp"
        -- kind "ConsoleApp"
        kind "SharedLib"
        language "C++"
        -- place where sources are
        files {  "src/**.cpp" }
        -- the output location
        location "build"
        -- the target lib output location
        targetdir "build/lib"
        -- includes 
        includedirs { "include", luapath }
        -- linking
        -- libdirs { luapath } 
        -- links { "lua" }
        

        if os.get() == "macosx" then
            linkoptions { "-undefined dynamic_lookup" }
        elseif os.get() == "windows" then
            -- not sure what to do here yet
            print("Windows options not specified")
        else
            linkoptions { "-shared" }
        end

        configuration "Debug"
            defines { "DEBUG " }
            flags { "Symbols" }

        configuration "Release"
            flags { "Optimize" }

    project "LuaCppTest"
        kind "ConsoleApp"
        language "C++"
        files { "test/src/*.cpp" }
        location "build"
        libdirs { "build/lib" }
        includedirs { "include", "test/include/**.h" }
        links { "LuaCpp" }
