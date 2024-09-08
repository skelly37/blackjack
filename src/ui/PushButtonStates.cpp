#include "ui/PushButtonStates.hpp"
#include "communication/GameStatus.hpp"
#include <iostream>

QString HitButtonState::text() const {
    return "Hit";
}

std::function<void()> HitButtonState::callback() const {
    return [] {
               UserChoice::hit();
    };
}

std::unique_ptr<PushButtonState> HitButtonState::nextState() const {
    if(GameStatus::getStatus() == GameStatus::Status::FINISHED) {
        return std::make_unique<PlayAgainButtonState>();
    }
    return std::make_unique<HitButtonState>();
}

/////
QString StandButtonState::text() const {
    return "Stand";
}

std::function<void()> StandButtonState::callback() const {
    return [] {
               UserChoice::stand();
    };
}

std::unique_ptr<PushButtonState> StandButtonState::nextState() const {
    if(GameStatus::getStatus() == GameStatus::Status::FINISHED) {
        return std::make_unique<QuitButtonState>();
    }
    return std::make_unique<StandButtonState>();
}

//////////
QString PlayAgainButtonState::text() const {
    return "Play Again";
}

std::function<void()> PlayAgainButtonState::callback() const {
    return [] {
               GameStatus::start();
    };
}

std::unique_ptr<PushButtonState> PlayAgainButtonState::nextState() const {
    if(GameStatus::getStatus() == GameStatus::Status::START_REQUESTED) {
        return std::make_unique<HitButtonState>();
    }
    return std::make_unique<PlayAgainButtonState>();
}

///////////
QString QuitButtonState::text() const {
    return "Quit";
}

std::function<void()> QuitButtonState::callback() const {
    return [] {
               GameStatus::stop();
    };
}

std::unique_ptr<PushButtonState> QuitButtonState::nextState() const {
    if(GameStatus::getStatus() == GameStatus::Status::START_REQUESTED) {
        return std::make_unique<StandButtonState>();
    }
    return std::make_unique<QuitButtonState>();
}
