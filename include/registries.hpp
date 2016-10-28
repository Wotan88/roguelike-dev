#ifndef INCLUDE_REGISTRIES_HPP_
#define INCLUDE_REGISTRIES_HPP_
#include "level.hpp"

namespace game {
namespace tileregistry {
game::Tile* getTile(int id);
void registerTile(game::Tile* t);
}
}

#endif
