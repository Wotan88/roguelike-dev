#ifndef INCLUDE_GAME_HPP_
#define INCLUDE_GAME_HPP_
#include <SDL2/SDL_events.h>
#include "easylogging++.h"
#include "graphics.hpp"
#include "input.hpp"

// GLOBAL 2DO SECTION:
// TODO: logging?
//
#define G game::getInstance()
#define GR game::getInstance()->renderer()

namespace game {
// Forward declaration
class GameClass;

// Instance of current GameClass
GameClass* getInstance();

class GameClass {
public:
    GameClass();
    virtual ~GameClass();

    game::Input* input();
    game::gfx::Renderer* renderer();

    void run();
    void onSDLEvent(SDL_Event* e);
private:
    bool mRunning;
    game::gfx::Renderer* mRenderer;
    game::Input* mInput;

    void render();
    void tick();
};
}

#endif
