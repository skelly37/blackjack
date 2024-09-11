#pragma once

#include "ui/bottom_button_states/BottomButtonState.hpp"

class QuitButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString text() const override;
    [[nodiscard]] std::function<void()> callback() const override;
    [[nodiscard]] std::unique_ptr<PushButtonState> nextState() const override;
};