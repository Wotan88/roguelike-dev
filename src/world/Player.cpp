#include "level.hpp"

game::Player::Player(game::Level* l) :
        Entity(l) {

}

game::Player::~Player() {
}

int game::Player::getBackgroundColor() {
    return -1;
}

int game::Player::getForegroundColor() {
    return 0xFF00;
}

int game::Player::getIconIndex() {
    return '@';
}
