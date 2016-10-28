#ifndef INCLUDE_GRAPHICS_HPP_
#define INCLUDE_GRAPHICS_HPP_
#include <SDL2/SDL.h>
#include "util.hpp"

// TODO: resizing window
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

namespace game {
namespace gfx {
class Renderer {
public:
    Renderer();
    ~Renderer();

    int initialize();
    void pullEvents();
    void render();
private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    SDL_Surface* mTileset;
    SDL_Event mSdlEvent;

    // TODO: naming conv.
    bool fpsCap;
    int frame;
    game::Timer fps;

    void renderInternal();
    int loadResources();
};
}
}

#endif
