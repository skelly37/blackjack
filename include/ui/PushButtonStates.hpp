#pragma once

#include <QString>

class PushButtonState {
public:
    virtual ~PushButtonState() = default;

    [[nodiscard]] virtual QString text() const = 0;
    [[nodiscard]] virtual std::function<void()> callback() const = 0;
    [[nodiscard]] virtual std::unique_ptr<PushButtonState> nextState() const = 0;
};


class HitButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString text() const override;
    [[nodiscard]] std::function<void()> callback() const override;
    [[nodiscard]] std::unique_ptr<PushButtonState> nextState() const override;
};

class StandButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString text() const override;
    [[nodiscard]] std::function<void()> callback() const override;
    [[nodiscard]] std::unique_ptr<PushButtonState> nextState() const override;
};

class PlayAgainButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString text() const override;
    [[nodiscard]] std::function<void()> callback() const override;
    [[nodiscard]] std::unique_ptr<PushButtonState> nextState() const override;
};

class QuitButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString text() const override;
    [[nodiscard]] std::function<void()> callback() const override;
    [[nodiscard]] std::unique_ptr<PushButtonState> nextState() const override;
};