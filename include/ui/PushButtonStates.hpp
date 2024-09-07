#pragma once

#include <QString>

class PushButtonState {
public:
    virtual ~PushButtonState() = default;

    [[nodiscard]] virtual QString text() const = 0;
    [[nodiscard]] virtual std::function<void()> callback() const = 0;
};

class HitButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString text() const override {
        return "Hit";
    }
    [[nodiscard]] std::function<void()> callback() const override {
        return [] {
        };
    }
};

class StandButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString text() const override {
        return "Stand";
    }
    [[nodiscard]] std::function<void()> callback() const override {
        return [] {
        };
    }
};

class PlayAgainButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString text() const override {
        return "Play again";
    }
    [[nodiscard]] std::function<void()> callback() const override {
        return [] {
        };
    }
};

class QuitButtonState final : public PushButtonState {
public:
    [[nodiscard]] QString text() const override {
        return "Quit";
    }
    [[nodiscard]] std::function<void()> callback() const override {
        return [] {
        };
    }
};