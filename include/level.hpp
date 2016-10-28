#ifndef INCLUDE_LEVEL_HPP_
#define INCLUDE_LEVEL_HPP_
#define MAX_TILE_ID 2048
#include <vector>

namespace game {
class Tile;
class Level;
class Entity;

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
    std::vector<game::Entity*> mEntities;
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

// Abstract entity class
class Entity {
public:
    Entity();
    virtual ~Entity();

    // Getters
    virtual int getIconIndex();
    virtual int getForegroundColor();
    virtual int getBackgroundColor();

    // Events
    virtual int onTurnFinished();
protected:
    game::Level* mLevel;
    int mX, mY;
};

// Player class
class Player: public Entity {
public:
    Player();
    virtual ~Player();

    // Getters
    int getIconIndex() override;
    int getForegroundColor() override;
    int getBackgroundColor() override;
private:
    // TODO: here will be stats
};
}

#endif
