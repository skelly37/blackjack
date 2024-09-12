#include "ui/bottom_button_states/QuitButtonState.hpp"
#include "ui/bottom_button_states/StandButtonState.hpp"
#include "communication/GameStatus.hpp"
#include "communication/UserChoice.hpp"

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