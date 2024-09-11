#pragma once

#include "ui/bottom_button_states/PushButtonState.hpp"

class StandButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString text() const override;
    [[nodiscard]] std::function<void()> callback() const override;
    [[nodiscard]] std::unique_ptr<PushButtonState> nextState() const override;
};