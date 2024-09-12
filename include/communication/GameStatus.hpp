#pragma once

class GameStatus {
public:
    GameStatus() = delete;
    GameStatus(const GameStatus &) = delete;
    GameStatus(GameStatus &&) = delete;
    GameStatus &operator=(const GameStatus &) = delete;
    GameStatus &operator=(GameStatus &&) = delete;

    enum class Status {
        FINISHED,
        START_REQUESTED,
        STOP_REQUESTED,
    };

    static void start();
    static void finish();
    static void stop();
    [[nodiscard]] static Status getStatus();

private:
    static inline Status status = Status::START_REQUESTED;
};