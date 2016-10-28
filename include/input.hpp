#ifndef INCLUDE_INPUT_HPP_
#define INCLUDE_INPUT_HPP_
#include <SDL2/SDL_events.h>
#include "easylogging++.h"

namespace game {
class Input {
public:
    Input();
    virtual ~Input();

    void keyDownEvent(SDL_KeyboardEvent kbd_ev);
private:

};
}

#endif
