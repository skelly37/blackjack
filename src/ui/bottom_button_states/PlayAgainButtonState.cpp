#include "ui/bottom_button_states/PlayAgainButtonState.hpp"
#include "ui/bottom_button_states/HitButtonState.hpp"
#include "communication/GameStatus.hpp"

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