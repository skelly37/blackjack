#include "ui/bottom_button_states/PlayAgainButtonState.hpp"
#include "ui/bottom_button_states/HitButtonState.hpp"
#include "communication/GameStatus.hpp"
#include "communication/UserChoice.hpp"

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