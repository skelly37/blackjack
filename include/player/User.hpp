#pragma once

#include "player/Player.hpp"

class User : public Player {
public:
    explicit User(std::string&& name = "User");

    void move(Deck& deck) override;
    [[nodiscard]] std::size_t getAmountOfPointsToForceStand() const override;

private:
    void doMove(Deck &deck);
};