#include "game.hpp"

game::GameClass::GameClass() {
    // TODO: throw an exception of GameClass instance already exists
    game::gameInstance = this;
}

game::GameClass::~GameClass() {
}

void game::GameClass::run() {

}
