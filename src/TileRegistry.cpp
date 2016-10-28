#include "registries.hpp"

void game::tileregistry::registerTile(game::Tile* t) {
	int id = t->getId();
	// TODO: throw exception on ID conflict
	game::tileregistry::tiles[id] = t;
}
