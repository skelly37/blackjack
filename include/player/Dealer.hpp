#pragma once

#include "player/Player.hpp"


class Dealer : public Player  {
public:
    Dealer();

    void move(Deck& deck) override;
};