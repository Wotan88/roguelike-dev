#include "graphics.hpp"
#include "game.hpp"
#include <iostream>

game::gfx::Renderer::Renderer() {
    this->mWindow = nullptr;
    this->mRenderer = nullptr;
    this->mTileset = nullptr;
    this->fpsCap = true;
    this->frame = 0;
}

game::gfx::Renderer::~Renderer() {
    if (this->mTileset) {
        SDL_FreeSurface(this->mTileset);
    }
    if (this->mRenderer) {
        SDL_DestroyRenderer(this->mRenderer);
    }
    if (this->mWindow) {
        SDL_DestroyWindow(this->mWindow);
    }
}

int game::gfx::Renderer::initialize() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << "SDL_Init failed" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        // Failed, return 0
        return 0;
    }

    // Create SDL window object
    // TODO: window title
    this->mWindow = SDL_CreateWindow("Window title", 100, 100, 800, 600,
            SDL_WINDOW_SHOWN);

    if (!this->mWindow) {
        std::cout << "SDL_CreateWindow failed" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return 0;
    }

    // Create SDL renderer object
    this->mRenderer = SDL_CreateRenderer(this->mWindow, -1,
            SDL_RENDERER_SOFTWARE);
    if (!this->mRenderer) {
        std::cout << "SDL_CreateRenderer failed" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return 0;
    }

    if (!loadResources()) {
        return 0;
    }

    return 1;
}

int game::gfx::Renderer::loadResources() {
    return 1;
}

void game::gfx::Renderer::renderInternal(){

}

void game::gfx::Renderer::render() {
    this->fps.start();

    while (SDL_PollEvent(&this->mSdlEvent)) {
        if (G) {
            G->onSDLEvent(&this->mSdlEvent);
        }
    }

    this->renderInternal();

    this->frame++;

    if (this->fpsCap == true && (fps.getTicks() < 1000 / 60)) {
        SDL_Delay((1000 / 60) - fps.getTicks());
    }
}
