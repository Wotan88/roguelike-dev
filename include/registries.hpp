#ifndef INCLUDE_REGISTRIES_HPP_
#define INCLUDE_REGISTRIES_HPP_
#include "level.hpp"

namespace game {
namespace tileregistry {
static Tile* tiles[MAX_TILE_ID];

void registerTile(game::Tile* t);
}
}

#endif
