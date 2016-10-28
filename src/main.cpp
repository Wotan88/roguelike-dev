#include "game.hpp"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char** argv) {
    game::GameClass i;
    i.run();
    return 0;
}
