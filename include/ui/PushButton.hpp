#pragma once

#include "PushButtonStates.hpp"

#include <QPushButton>

class PushButton final : public QPushButton {
public:
    explicit PushButton(std::unique_ptr<PushButtonState> initial_state, QWidget* parent = nullptr);

    void setNextState();
    void setState(std::unique_ptr<PushButtonState> state);

private:
    std::unique_ptr<PushButtonState> state;
    std::function<void()> callback;
};