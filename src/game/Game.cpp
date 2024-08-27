#include "game/Game.hpp"

void Game::play() {
    initializeGame();
    hitAndStandLoop();
    finalizeGame();
}
