#include "registries.hpp"

static game::Tile* tiles[MAX_TILE_ID];

game::Tile* game::tileregistry::getTile(int id){
    // TODO: sanity checks
    return tiles[id];
}

void game::tileregistry::registerTile(game::Tile* t) {
    int id = t->getId();
    // TODO: throw exception on ID conflict
    tiles[id] = t;
}
