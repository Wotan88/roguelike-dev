# Files
CXXSources:=src/main.cpp\
			src/GameClass.cpp\
			src/TileRegistry.cpp\
			src/world/Level.cpp\
			src/world/Tile.cpp\
			src/util/Timer.cpp\
			src/graphics/Renderer.cpp

# Output
CXXObjects:=$(patsubst src/%.cpp,build/%.o,$(CXXSources))
OutputDirs:=build/ build/world/ build/util build/graphics

# Compiler params
CXX:=g++
LD:=g++
CXX_FLAGS:=--pedantic -O2 -Wall -Iinclude/ `pkg-config --cflags sdl2`
LD_FLAGS:=`pkg-config --libs sdl2`


all: build/roguelike

build/roguelike: makedirs tplibs $(CXXObjects)
	$(LD) $(LD_FLAGS) -o $@ $(CXXObjects)

build/%.o: src/%.cpp
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

makedirs:
	@mkdir -p $(OutputDirs)
	
tplibs:
	make -C lib/src/SDL2_Image/

run: build/roguelike
	build/roguelike