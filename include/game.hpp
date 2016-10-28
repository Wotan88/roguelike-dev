#ifndef INCLUDE_GAME_HPP_
#define INCLUDE_GAME_HPP_
#include "graphics.hpp"
#include <SDL2/SDL_events.h>
#include "easylogging++.h"

// GLOBAL 2DO SECTION:
// TODO: logging?
//
#define G game::getInstance()

namespace game {
// Forward declaration
class GameClass;

// Instance of current GameClass
GameClass* getInstance();

class GameClass {
public:
    GameClass();
    virtual ~GameClass();

    void run();
    void onSDLEvent(SDL_Event* e);
private:
    bool mRunning;
    game::gfx::Renderer* mRenderer;

    void render();
    void tick();
};
}

#endif
