#pragma once

#include "BottonButtonStates.hpp"

#include <QPushButton>

class PushButton final : public QPushButton {
public:
    explicit PushButton(std::unique_ptr<PushButtonState> initial_state, QWidget* parent = nullptr);

    void setNextState();
    void setState(std::unique_ptr<PushButtonState> state);

private:
    void executeCallback();

    std::unique_ptr<PushButtonState> state;
    std::function<void()> callback;
};