# Files
CXXSources:=src/main.cpp\
			src/GameClass.cpp\
			src/Input.cpp\
			src/TileRegistry.cpp\
			src/world/Level.cpp\
			src/world/Tile.cpp\
			src/util/Timer.cpp\
			src/graphics/Renderer.cpp

# Output
CXXObjects:=$(patsubst src/%.cpp,build/%.o,$(CXXSources))
OutputDirs:=build/ build/world/ build/util build/graphics

# Third-party
ThirdPartyObjects:=lib/src/SDL2_Image/IMG.o lib/src/SDL2_Image/IMG_bmp.o lib/src/SDL2_Image/IMG_png.o lib/src/SDL2_Image/IMG_tga.o

# Compiler params
G++6X := $(shell command -v g++-6 2> /dev/null)
CXX:=$(if $(G++6X),g++-6,g++)
LD:=$(if $(G++6X),g++-6,g++)
CXX_FLAGS:=-std=c++11 --pedantic -O2 -Wall -Iinclude/ -Ilib/include/ `sdl2-config --cflags`
LD_FLAGS:=`sdl2-config --libs`


all: build/roguelike

build/roguelike: makedirs tplibs $(CXXObjects)
	$(LD) -o $@ $(CXXObjects) $(LD_FLAGS) $(ThirdPartyObjects)

build/%.o: src/%.cpp
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

makedirs:
	@mkdir -p $(OutputDirs)
	
tplibs:
	make -C lib/src/SDL2_Image/

run: build/roguelike
	build/roguelike

clean:
	rm -rf build/