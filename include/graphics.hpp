#ifndef INCLUDE_GRAPHICS_HPP_
#define INCLUDE_GRAPHICS_HPP_
#include <SDL2/SDL.h>
#include "easylogging++.h"
#include <string>
#include "util.hpp"

// TODO: resizing window
#define CHAR_WIDTH 16
#define CHAR_HEIGHT 24

#define SCREEN_WIDTH CHAR_WIDTH * 80
#define SCREEN_HEIGHT CHAR_HEIGHT * 24

namespace game {
namespace gfx {
class Texture {
public:
    Texture(SDL_Texture* t, int w, int h);
    virtual ~Texture();

    void freeTexture();
    void setBlend(SDL_BlendMode mode);
    void setAlpha(unsigned char alpha);
    void setColorMask(unsigned int rgb);
    void render(SDL_Rect* bounds, SDL_Rect* clip = nullptr);

    int width();
    int height();
private:
    SDL_Texture* mTexture;

    int mWidth, mHeight;
};

Texture* loadTexture(const std::string& filename);

class Renderer {
public:
    Renderer();
    ~Renderer();

    SDL_Renderer* sdlRenderer();

    int initialize();
    void pullEvents();
    void render();
private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    SDL_Event mSdlEvent;

    game::gfx::Texture* mTileset;

    // TODO: naming conv.
    bool fpsCap;
    int frame;
    game::Timer fps;

    void renderInternal();

    void renderCharacter(int c, int x, int y, int fg, int bg);

    int loadResources();
};
}
}

#endif
