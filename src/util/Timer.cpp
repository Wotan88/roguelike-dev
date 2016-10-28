#include "util.hpp"
#include <SDL2/SDL.h>

game::Timer::Timer() {
    this->mStartTicks = this->mPausedTicks = 0;
    this->mPaused = this->mStarted = false;
}

void game::Timer::start() {
    this->mStarted = true;
    this->mPaused = false;
    this->mStartTicks = SDL_GetTicks();
    this->mPausedTicks = 0;
}

void game::Timer::stop() {
    this->mStarted = false;
    this->mPaused = false;
    this->mStartTicks = 0;
    this->mPausedTicks = 0;
}

void game::Timer::pause() {
    if (this->mStarted && !this->mPaused) {
        this->mPaused = true;
        this->mPausedTicks = SDL_GetTicks() - this->mStartTicks;
        this->mStartTicks = 0;
    }
}

void game::Timer::unpause() {
    if (this->mStarted && this->mPaused) {
        this->mPaused = false;
        this->mStartTicks = SDL_GetTicks() - this->mPausedTicks;
        this->mPausedTicks = 0;
    }
}

Uint32 game::Timer::getTicks() {
    Uint32 time = 0;

    if (this->mStarted) {
        if (this->mPaused) {
            time = this->mPausedTicks;
        } else {
            time = SDL_GetTicks() - this->mStartTicks;
        }
    }

    return time;
}

bool game::Timer::isPaused(){
    return this->mPaused && this->mStarted;
}

bool game::Timer::isStarted(){
    return this->mStarted;
}
