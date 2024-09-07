#pragma once

#include <QString>

class PushButtonState {
public:
    virtual ~PushButtonState() = default;

    [[nodiscard]] virtual QString text() const = 0;
    [[nodiscard]] virtual std::function<void()> callback() const = 0;
};

class HitButtonState : public PushButtonState {
public:
    [[nodiscard]] QString text() const override {
        return "Hit";
    }
    [[nodiscard]] std::function<void()> callback() const override {
        return [] {
        };
    }
};

class StandButtonState : public PushButtonState {
public:
    [[nodiscard]] QString text() const override {
        return "Stand";
    }
    [[nodiscard]] std::function<void()> callback() const override {
        return [] {
        };
    }
};

class PlayAgainButtonState : public PushButtonState {
public:
    [[nodiscard]] QString text() const override {
        return "Play again";
    }
    [[nodiscard]] std::function<void()> callback() const override {
        return [] {
        };
    }
};

class QuitButtonState : public PushButtonState {
public:
    [[nodiscard]] QString text() const override {
        return "Quit";
    }
    [[nodiscard]] std::function<void()> callback() const override {
        return [] {
        };
    }
};