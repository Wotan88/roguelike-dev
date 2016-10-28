#ifndef INCLUDE_LEVEL_HPP_
#define INCLUDE_LEVEL_HPP_
#define MAX_TILE_ID 2048

namespace game {
class Tile;
class Level;

class Level {
public:
	Level(int width, int height);
	virtual ~Level();

	// Getters
	int get(int x, int y);

	// Setters
	int set(int x, int y, int t);
	int set(int x, int y, Tile* t);
private:
	int mWidth, mHeight;
	int* mMatrix;
};

// Abstract tile class
// (Basic functions implemented by TileGeneric)
class Tile {
public:
	Tile(int id);
	virtual ~Tile();

	// Getters
	virtual int getIconIndex(int x, int y, Level* level);
	virtual int getForegroundColor(int x, int y, Level* level);
	virtual int getBackgroundColor(int x, int y, Level* level);

	int getId();

	// Events
	virtual int onTurnFinished(int x, int y, Level* level);
private:
	int mId;
};
}

#endif
