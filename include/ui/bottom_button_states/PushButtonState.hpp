#pragma once

#include <QString>

class PushButtonState {
public:
    virtual ~PushButtonState() = default;

    [[nodiscard]] virtual QString text() const = 0;
    [[nodiscard]] virtual std::function<void()> callback() const = 0;
    [[nodiscard]] virtual std::unique_ptr<PushButtonState> nextState() const = 0;
};