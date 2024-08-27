#include "Game.hpp"

void Game::play() {
    initializeGame();
    hitAndStandLoop();
    finalizeGame();
}
