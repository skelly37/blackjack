#include "player/Dealer.hpp"
#include <iostream>

Dealer::Dealer() : Player("Dealer") {
}

void Dealer::move(Deck& deck) {
    if(getCurrentScore() < 17) {
        addCard(deck.getCard());
    } else {
        stand();
    }
}
