#pragma once

#include "player/Player.hpp"
#include "io/IO.hpp"

class User : public Player {
public:
    explicit User(std::shared_ptr<IO> io, std::string&& name = "User");

    void move(Deck& deck) override;
    [[nodiscard]] std::size_t getAmountOfPointsToForceStand() const override;

private:
    std::shared_ptr<IO> io;
};