#include "game/Game.hpp"

Game::Game(std::shared_ptr<IO> io) : io(std::move(io)) {
}

void Game::play() {
    initializeGame();
    hitAndStandLoop();
    finalizeGame();
}
