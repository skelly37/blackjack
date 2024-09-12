#include "communication/GameStatus.hpp"


void GameStatus::finish() {
    status = Status::FINISHED;
}

void GameStatus::stop() {
    status = Status::STOP_REQUESTED;
}

void GameStatus::start() {
    status = Status::START_REQUESTED;
}

GameStatus::Status GameStatus::getStatus() {
    return status;
}
