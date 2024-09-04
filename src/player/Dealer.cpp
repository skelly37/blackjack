#include "player/Dealer.hpp"
#include <iostream>

Dealer::Dealer() : Player("Dealer") {
}

void Dealer::move(Deck& deck) {
    if(shouldMove()) {
        addCard(deck.getCard());
    } else {
        stand();
    }
}

std::size_t Dealer::getAmountOfPointsToForceStand() const {
    return 17;
}
