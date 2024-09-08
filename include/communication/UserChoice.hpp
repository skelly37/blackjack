#pragma once
#include <mutex>
#include <optional>

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
    static inline std::mutex read_mtx;
    static inline std::mutex write_mtx;
    static inline std::optional<Action> action = std::nullopt;
};
