#include "level.hpp"

game::Entity::Entity(game::Level* l) {
    this->mLevel = l;
    this->mX = 0;
    this->mY = 0;
}

game::Entity::~Entity() {

}

int game::Entity::getBackgroundColor() {
    return -1;
}

int game::Entity::getForegroundColor() {
    return 0xFFFFFF;
}

int game::Entity::getIconIndex() {
    return '?';
}

int game::Entity::onTurnFinished() {
    return 1;
}

void game::Entity::getPosition(int& x, int& y) {
    x = this->mX;
    y = this->mY;
}

int game::Entity::x() {
    return this->mX;
}

int game::Entity::y() {
    return this->mY;
}

int game::Entity::move(int x, int y) {
    if (!this->mLevel){
        LOG(WARNING)<< "game::Entity::move(): mLevel == nullptr!";
        return 0;
    }
    if (x < 0 || y < 0 || x >= this->mLevel->width()
            || y >= this->mLevel->height())
        return 0;
    this->mX = x;
    this->mY = y;
    return 1;
}
