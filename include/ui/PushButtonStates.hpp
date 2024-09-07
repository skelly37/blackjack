#pragma once

#include <QString>

class PushButtonState {
public:
    virtual ~PushButtonState() = default;

    [[nodiscard]] virtual QString* text() const = 0;
    [[nodiscard]] virtual std::function<void()> callback() const = 0;
};

class HitButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString* text() const override {
        return new QString{"Hit"};
    }
    [[nodiscard]] std::function<void()> callback() const override {
        return [] {
        };
    }
};

class StandButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString* text() const override {
        return new QString{"Stand"};
    }
    [[nodiscard]] std::function<void()> callback() const override {
        return [] {
        };
    }
};

class PlayAgainButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString* text() const override {
        return new QString{"Play again"};
    }
    [[nodiscard]] std::function<void()> callback() const override {
        return [] {
        };
    }
};

class QuitButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString* text() const override {
        return new QString{"Quit"};
    }
    [[nodiscard]] std::function<void()> callback() const override {
        return [] {
        };
    }
};