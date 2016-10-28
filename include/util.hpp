#ifndef INCLUDE_UTIL_HPP_
#define INCLUDE_UTIL_HPP_
#include <SDL2/SDL_types.h>

namespace game {
class Timer {
public:
    Timer();
    void start();
    void stop();
    void pause();
    void unpause();
    Uint32 getTicks();
    bool isStarted();
    bool isPaused();
private:
    Uint32 mStartTicks;
    Uint32 mPausedTicks;
    bool mPaused;
    bool mStarted;
};
}

#endif
