#pragma once
#include <mutex>
#include <optional>

class AppClosedException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class UserChoice {
public:
    UserChoice() = delete;
    UserChoice(const UserChoice&) = delete;
    UserChoice(UserChoice&&) = delete;
    UserChoice& operator=(const UserChoice&) = delete;
    UserChoice& operator=(UserChoice&&) = delete;

    enum class Action {
        HIT,
        STAND,
    };

    static void hit();
    static void stand();
    [[nodiscard]] static Action getChoice();

private:
    static inline std::mutex mtx;
    static inline std::optional<Action> action = std::nullopt;
};
