# Files
CXXSources:=$(shell find src/ -name *.cpp -type f)

# Output
CXXObjects:=$(patsubst src/%.cpp,build/%.o,$(CXXSources))
OutputDirs:=build/ build/world/ build/util build/graphics

# Third-party
ThirdPartyObjects:=

# Compiler params
G++6X := $(shell command -v g++-6 2> /dev/null)
CXX:=$(if $(G++6X),g++-6,g++)
LD:=$(if $(G++6X),g++-6,g++)
CXX_FLAGS:=-std=c++11 --pedantic -O2 -Wall -Iinclude/ -Ilib/include/ `sdl2-config --cflags`
LD_FLAGS:=`sdl2-config --libs` `pkg-config --libs SDL2_image`


all: build/roguelike

build/roguelike: makedirs tplibs $(CXXObjects)
	$(LD) -o $@ $(CXXObjects) $(LD_FLAGS) $(ThirdPartyObjects)

build/%.o: src/%.cpp
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

makedirs:
	@mkdir -p $(OutputDirs)
	
tplibs:
	

run: build/roguelike
	build/roguelike

clean:
	rm -rf build/