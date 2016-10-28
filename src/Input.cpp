#include "input.hpp"
#include "game.hpp"

game::Input::Input() {

}

game::Input::~Input() {

}

void game::Input::keyDownEvent(SDL_KeyboardEvent e) {
    if (e.keysym.scancode == SDL_SCANCODE_KP_4) {
        GP->move(GP->x()-1, GP->y());
    }
    if (e.keysym.scancode == SDL_SCANCODE_KP_6) {
        GP->move(GP->x()+1, GP->y());
    }
    if (e.keysym.scancode == SDL_SCANCODE_KP_8) {
        GP->move(GP->x(), GP->y()-1);
    }
    if (e.keysym.scancode == SDL_SCANCODE_KP_2) {
        GP->move(GP->x(), GP->y()+1);
    }

    GR->render();
}
