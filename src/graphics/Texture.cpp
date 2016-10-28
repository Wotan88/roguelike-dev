#include "graphics.hpp"
#include <SDL2/SDL_image.h>
#include "game.hpp"

game::gfx::Texture* game::gfx::loadTexture(const std::string& filename) {
    LOG(INFO)<< "game::gfx::loadTexture(): " << filename;

    game::gfx::Texture* ret = nullptr;
    SDL_Texture* tex = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
    if(!loadedSurface) {
        LOG(ERROR)<<"Unable to load image! SDL_image Error: "<< IMG_GetError();
    } else {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ));
        tex = SDL_CreateTextureFromSurface(GR->sdlRenderer(), loadedSurface);
        if(!tex) {
            LOG(ERROR) << "Failed to create texture! SDL Error: "<<SDL_GetError();
        } else {
            ret = new game::gfx::Texture(tex, loadedSurface->w, loadedSurface->h);
        }
        SDL_FreeSurface(loadedSurface);
    }

    return ret;
}

game::gfx::Texture::Texture(SDL_Texture* t, int w, int h) {
    this->mTexture = t;
    this->mWidth = w;
    this->mHeight = h;
}

game::gfx::Texture::~Texture() {
    if (this->mTexture) {
        this->freeTexture();
    }
}

int game::gfx::Texture::width() {
    return this->mWidth;
}

int game::gfx::Texture::height() {
    return this->mHeight;
}

void game::gfx::Texture::freeTexture() {
    SDL_DestroyTexture(this->mTexture);
}

void game::gfx::Texture::render(SDL_Rect* bounds, SDL_Rect* clip) {
    SDL_RenderCopy(GR->sdlRenderer(), this->mTexture, clip, bounds);
}

void game::gfx::Texture::setColorMask(unsigned int rgb) {
    SDL_SetTextureColorMod(this->mTexture, (rgb >> 16) & 0xFF,
            (rgb >> 8) & 0xFF, rgb & 0xFF);
}
