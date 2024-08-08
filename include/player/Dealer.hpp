#pragma once

#include "player/Player.hpp"


class Dealer : public Player  {
public:
    Dealer();

    void move(Deck& deck) override;
    [[nodiscard]] std::size_t getAmountOfPointsToForceStand() const override;
};