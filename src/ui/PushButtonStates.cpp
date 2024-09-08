#include "ui/PushButtonStates.hpp"

QString HitButtonState::text() const {
    return "Hit";
}

std::function<void()> HitButtonState::callback() const {
    return [] {
               UserChoice::hit();
    };
}

std::unique_ptr<PushButtonState> HitButtonState::nextState() const {
    return std::make_unique<PlayAgainButtonState>();
}

QString StandButtonState::text() const {
    return "Stand";
}

std::function<void()> StandButtonState::callback() const {
    return [] {
               UserChoice::stand();
    };
}

std::unique_ptr<PushButtonState> StandButtonState::nextState() const {
    return std::make_unique<QuitButtonState>();
}

QString PlayAgainButtonState::text() const {
    return "Play Again";
}

std::function<void()> PlayAgainButtonState::callback() const {
    return [] {
               //todo
    };
}

std::unique_ptr<PushButtonState> PlayAgainButtonState::nextState() const {
    return std::make_unique<HitButtonState>();
}

QString QuitButtonState::text() const {
    return "Quit";
}

std::function<void()> QuitButtonState::callback() const {
    return [] {
               //todo
    };
}

std::unique_ptr<PushButtonState> QuitButtonState::nextState() const {
    return std::make_unique<StandButtonState>();
}
