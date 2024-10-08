#include "player/User.hpp"

#include <iostream>

#include "communication/UserChoice.hpp"

User::User(std::string&& name) : Player(std::move(name)) {
}

void User::move(Deck &deck) {
    try {
        doMove(deck);
    } catch (const AppClosedException&) {
        stand();
    }
}

void User::doMove(Deck &deck) {
    if (shouldMove() && UserChoice::getChoice() == UserChoice::Action::HIT) {
        addCard(deck.getCard());
    } else {
        stand();
    }
}

std::size_t User::getAmountOfPointsToForceStand() const {
    return 22;
}

