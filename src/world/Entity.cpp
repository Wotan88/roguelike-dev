#include "level.hpp"

game::Entity::Entity() {
    this->mLevel = nullptr;
    this->mX = 0;
    this->mY = 0;
}

game::Entity::~Entity() {

}

int game::Entity::getBackgroundColor(){
    return 0;
}

int game::Entity::getForegroundColor(){
    return 0xFFFFFF;
}

int game::Entity::getIconIndex(){
    return '?';
}

int game::Entity::onTurnFinished(){
    return 1;
}
