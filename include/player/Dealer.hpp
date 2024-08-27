#pragma once

#include "Player.hpp"


class Dealer : public Player  {
public:
    Dealer();

    void move(Deck& deck) override;
};