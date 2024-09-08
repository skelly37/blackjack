#include "communication/GameStatus.hpp"


void GameStatus::start() {
    is_finished = false;
}

void GameStatus::finish() {
    is_finished = true;
}

[[nodiscard]] bool GameStatus::isFinished() {
    return is_finished;
}