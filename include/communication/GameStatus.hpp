#pragma once

class GameStatus {
public:
    GameStatus() = delete;
    GameStatus(const GameStatus &) = delete;
    GameStatus(GameStatus &&) = delete;
    GameStatus &operator=(const GameStatus &) = delete;
    GameStatus &operator=(GameStatus &&) = delete;

    static void start();
    static void finish();
    [[nodiscard]] static bool isFinished();

private:
    static inline bool is_finished = true;
};