#pragma once

#include "PushButtonStates.hpp"

#include <QPushButton>

class PushButton : public QPushButton {
public:
    PushButton(std::unique_ptr<PushButtonState> initial_state, QWidget* parent = nullptr);

    void setState(std::unique_ptr<PushButtonState> state);

private:
    std::unique_ptr<PushButtonState> state;
    std::function<void()> callback;
};