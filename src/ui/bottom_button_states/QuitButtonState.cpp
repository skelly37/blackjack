#include "ui/bottom_button_states/QuitButtonState.hpp"
#include "ui/bottom_button_states/StandButtonState.hpp"
#include "communication/GameStatus.hpp"

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