#include "game.hpp"
#include <iostream>

static game::GameClass* instance = nullptr;

game::GameClass* game::getInstance() {
    return instance;
}

game::GameClass::GameClass() {
    this->mRenderer = nullptr;
    this->mRunning = false;

    // TODO: throw an exception of GameClass instance already exists
    instance = this;
}

game::GameClass::~GameClass() {
}

void game::GameClass::run() {
    this->mRenderer = new game::gfx::Renderer();
    if (!this->mRenderer->initialize()) {
        return;
    }
    this->mRunning = true;

    while (this->mRunning) {
        this->mRenderer->render();
    }

    delete this->mRenderer;
    SDL_Quit();
}

void game::GameClass::onSDLEvent(SDL_Event* e) {
    if (e->type == SDL_QUIT) {
        std::cout << "Quit event";
        this->mRunning = false;
    }
}
