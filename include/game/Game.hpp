#pragma once

#include "io/IO.hpp"

#include <memory>

class Game {
public:
    explicit Game(std::shared_ptr<IO> io);
    virtual ~Game() = default;

    void play();
protected:
    virtual void initializeGame() = 0;
    virtual void hitAndStandLoop() = 0;
    virtual void finalizeGame() = 0;

    std::shared_ptr<IO> io;
};