#include "game.hpp"

static game::GameClass* instance = nullptr;

game::GameClass* game::getInstance() {
    return instance;
}

game::GameClass::GameClass() {
    this->mRenderer = nullptr;
    this->mInput = nullptr;

    this->mPlayer = nullptr;
    this->mCurrentLevel = nullptr;

    this->mRunning = false;

    // TODO: throw an exception of GameClass instance already exists
    instance = this;
}

game::GameClass::~GameClass() {
    LOG(DEBUG)<< "GameClass instance destroyed";
    delete this->mPlayer;
    delete this->mRenderer;
    delete this->mInput;
    delete this->mCurrentLevel;
}

void game::GameClass::setup() {
    // Input
    this->mInput = new game::Input();

    // Level
    this->mCurrentLevel = new game::Level(80, 24);

    // Player
    this->mPlayer = new game::Player(this->mCurrentLevel);
}

void game::GameClass::run() {
    LOG(INFO)<< "Starting";
    this->mRenderer = new game::gfx::Renderer();
    if (!this->mRenderer->initialize()) {
        return;
    }

    this->setup();

    // Game is now running
    this->mRunning = true;

    // First render
    this->mRenderer->render();

    while (this->mRunning) {
        this->mRenderer->pullEvents();
    }

    LOG(INFO)<< "Quitting";

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

game::gfx::Renderer* game::GameClass::renderer() {
    return this->mRenderer;
}

game::Player* game::GameClass::player() {
    return this->mPlayer;
}
