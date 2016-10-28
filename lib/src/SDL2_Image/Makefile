Sources:=IMG.c\
		IMG_png.c\
		IMG_bmp.c\
		IMG_tga.c

Output:=$(patsubst %.c, %.o, $(Sources))

# Compiler params
CXX:=g++
LD:=g++
CXX_FLAGS:=--pedantic -O2 -Wall `pkg-config --cflags sdl2` -I../../include/
LD_FLAGS:=`pkg-config --libs sdl2`

all: $(Output)

%.o: %.c
	$(CXX) $(CXX_FLAGS) -c -o $@ $<