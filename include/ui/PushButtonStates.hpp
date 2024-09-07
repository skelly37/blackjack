#pragma once

#include <QString>

class PushButtonState {
public:
    [[nodiscard]] virtual QString text() const = 0;
    [[nodiscard]] virtual std::function<void()> callback() const = 0;
};

class HitButtonState : public PushButtonState {
public:
    [[nodiscard]] virtual QString text() const override {
        return "Hit";
    }
    [[nodiscard]] virtual std::function<void()> callback() const override {
        return [] {
        };
    }
};

class StandButtonState : public PushButtonState {
public:
    [[nodiscard]] virtual QString text() const override {
        return "Stand";
    }
    [[nodiscard]] virtual std::function<void()> callback() const override {
        return [] {
        };
    }
};

class PlayAgainButtonState : public PushButtonState {
public:
    [[nodiscard]] virtual QString text() const override {
        return "Play again";
    }
    [[nodiscard]] virtual std::function<void()> callback() const override {
        return [] {
        };
    }
};

class QuitButtonState : public PushButtonState {
public:
    [[nodiscard]] virtual QString text() const override {
        return "Quit";
    }
    [[nodiscard]] virtual std::function<void()> callback() const override {
        return [] {
        };
    }
};