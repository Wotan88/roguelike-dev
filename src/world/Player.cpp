#include "level.hpp"

game::Player::Player() :
        Entity() {

}

game::Player::~Player() {
}

int game::Player::getBackgroundColor() {
    return 0;
}

int game::Player::getForegroundColor() {
    return 0xFF00;
}

int game::Player::getIconIndex() {
    return '@';
}
