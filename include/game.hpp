#ifndef INCLUDE_GAME_HPP_
#define INCLUDE_GAME_HPP_

namespace game {
// Forward declaration
class GameClass;

// Instance of current GameClass
static GameClass* gameInstance;

class GameClass {
public:
	GameClass();
	virtual ~GameClass();

	void run();
private:
	void render();
	void tick();
};
}

#endif
