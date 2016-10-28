#include "graphics.hpp"
#include <SDL2/SDL_image.h>
#include "game.hpp"

game::gfx::Renderer::Renderer() {
    this->mWindow = nullptr;
    this->mRenderer = nullptr;
    this->mTileset = nullptr;
    this->mFpsCap = true;
    this->mFrame = 0;
}

game::gfx::Renderer::~Renderer() {
    IMG_Quit();

    if (this->mTileset) {
        delete this->mTileset;
    }
    if (this->mRenderer) {
        SDL_DestroyRenderer(this->mRenderer);
    }
    if (this->mWindow) {
        SDL_DestroyWindow(this->mWindow);
    }
}

int game::gfx::Renderer::initialize() {
    LOG(INFO)<< "Initializing SDL";
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        LOG(ERROR)<< "SDL_Init failed";
        LOG(ERROR) << SDL_GetError();
        // Failed, return 0
        return 0;
    }

    LOG(INFO) << "Creating SDL window";
    // Create SDL window object
    // TODO: window title
    this->mWindow = SDL_CreateWindow("Window title", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);

    if (!this->mWindow) {
        LOG(ERROR) << "SDL_CreateWindow failed";
        LOG(ERROR) << SDL_GetError();
        return 0;
    }

    LOG(INFO) << "Creating SDL renderer";
    // Create SDL renderer object
    this->mRenderer = SDL_CreateRenderer(this->mWindow, -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!this->mRenderer) {
        LOG(ERROR) << "SDL_CreateRenderer failed";
        LOG(ERROR) << SDL_GetError();
        return 0;
    }

    IMG_Init(IMG_INIT_PNG);

    if (!loadResources()) {
        LOG(ERROR) << "Failed to load game resources";
        return 0;
    }

    return 1;
}

int game::gfx::Renderer::loadResources() {
    LOG(DEBUG)<< "Resource load stub";

    this->mTileset = game::gfx::loadTexture("assets/font.png");

    return 1;
}

void game::gfx::Renderer::renderInternal() {
    SDL_SetRenderDrawColor(this->mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(this->mRenderer);

    this->renderCharacter('X', 0, 0, 0xFF0000, 0xFFFFFF);

    SDL_RenderPresent(this->mRenderer);
}

void game::gfx::Renderer::renderCharacter(int c, int x, int y, int fg, int bg) {
    int tx = 0, ty = 0;
    tx = c % 16;
    ty = c / 16;
    // TODO: define this in variable/constant
    SDL_Rect r { tx * 8, ty * 12, 8, 12 };
    SDL_Rect r2 { x * CHAR_WIDTH, y * CHAR_HEIGHT, CHAR_WIDTH, CHAR_HEIGHT };
    if (fg >= 0) {
        this->mTileset->setColorMask(fg);
    }
    if (bg >= 0) {
        SDL_SetRenderDrawColor(this->mRenderer, (bg >> 16) & 0xFF,
                (bg >> 8) & 0xFF, bg & 0xFF, 255);
        SDL_RenderFillRect(this->mRenderer, &r2);
    }
    this->mTileset->render(&r2, &r);
}

void game::gfx::Renderer::pullEvents() {
    this->mFps.start();

    while (SDL_PollEvent(&this->mSdlEvent)) {
        if (G) {
            G->onSDLEvent(&this->mSdlEvent);
        }
    }

    if (this->mFpsCap == true && (mFps.getTicks() < 1000 / 60)) {
        SDL_Delay((1000 / 60) - mFps.getTicks());
    }
}

void game::gfx::Renderer::render() {
    this->renderInternal();
    this->mFrame++;
}

SDL_Renderer* game::gfx::Renderer::sdlRenderer() {
    return this->mRenderer;
}
