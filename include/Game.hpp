#pragma once

class Game {
public:
    virtual ~Game() = default;

    void play();
protected:
    virtual void initializeGame() = 0;
    virtual void hitAndStandLoop() = 0;
    virtual void finalizeGame() = 0;
};