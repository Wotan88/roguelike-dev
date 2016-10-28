#include "level.hpp"

// game::Level main constructor
game::Level::Level(int width, int height) :
		mWidth(width), mHeight(height) {
	// Allocate array of integers for tiles
	mMatrix = new int[mWidth * mHeight];
}

// game::Level main destructor
game::Level::~Level() {

}

// game::Level int getter
int game::Level::get(int x, int y) {
	// Sanity checks
	// XXX: maybe it's better to throw exception here
	if (x < 0 || y < 0 || x >= this->mWidth || y >= this->mHeight) {
		return -1;
	}

	return this->mMatrix[x + y * this->mWidth];
}

// game::Level int setter
int game::Level::set(int x, int y, int t) {
	// Sanity checks
	// XXX: maybe it's better to throw exception here (and change return type to void)
	if (x < 0 || y < 0 || x >= this->mWidth || y >= this->mHeight) {
		return 0;
	}

	this->mMatrix[x + y * this->mWidth] = t;

	return 1;
}
