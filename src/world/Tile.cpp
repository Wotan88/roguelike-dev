#include "level.hpp"

game::Tile::Tile(int id) :
        mId(id) {

}

game::Tile::~Tile() {

}

int game::Tile::getBackgroundColor(int x, int y, game::Level* level) {
    return 0;
}

int game::Tile::getForegroundColor(int x, int y, game::Level* level) {
    return 0xFFFFFF;
}

int game::Tile::getIconIndex(int x, int y, game::Level* level) {
    return '?';
}

int game::Tile::onTurnFinished(int x, int y, game::Level* level) {
    return 1;
}

int game::Tile::getId() {
    return this->mId;
}
