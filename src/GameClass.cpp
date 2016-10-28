#include "game.hpp"

static game::GameClass* instance = nullptr;

game::GameClass* game::getInstance() {
    return instance;
}

game::GameClass::GameClass() {
    this->mRenderer = nullptr;
    this->mInput = nullptr;
    this->mRunning = false;

    // TODO: throw an exception of GameClass instance already exists
    instance = this;
}

game::GameClass::~GameClass() {
}

void game::GameClass::run() {
    LOG(INFO)<< "Starting";
    this->mRenderer = new game::gfx::Renderer();
    if (!this->mRenderer->initialize()) {
        return;
    }

    // Input
    this->mInput = new game::Input();

    // Game is now running
    this->mRunning = true;

    // First render
    this->mRenderer->render();

    while (this->mRunning) {
        this->mRenderer->pullEvents();
    }

    LOG(INFO)<< "Quitting";
    delete this->mRenderer;
    SDL_Quit();
}

void game::GameClass::onSDLEvent(SDL_Event* e) {
    if (e->type == SDL_QUIT) {
        LOG(DEBUG)<< "SDL_QUIT event received";
        this->mRunning = false;
    }
    if (e->type == SDL_KEYDOWN) {
        this->mInput->keyDownEvent(e->key);
    }
}

game::Input* game::GameClass::input() {
    return this->mInput;
}
