# Files
CXXSources:=src/main.cpp

# Output
CXXObjects:=$(patsubst src/%.cpp,build/%.o,$(CXXSources))
OutputDirs:=build/

# Compiler params
CXX:=g++
LD:=g++
CXX_FLAGS:=--pedantic -O2 -Wall -Iinclude/
LD_FLAGS:=


all: build/roguelike

build/roguelike: makedirs $(CXXObjects)
	$(LD) $(LD_FLAGS) -o $@ $(CXXObjects)
	
build/%.o: src/%.cpp
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

makedirs:
	@mkdir -p $(OutputDirs)
	
run: build/roguelike
	build/roguelike