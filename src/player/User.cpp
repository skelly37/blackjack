#include "player/User.hpp"


User::User(std::shared_ptr<IO> io, std::string&& name) : Player(std::move(name)), io(std::move(io)) {
}

void User::move(Deck &deck) {
    if (shouldMove() && io->getUserChoice(this->NAME) == IO::UserChoice::HIT) {
        addCard(deck.getCard());
    } else {
        stand();
    }
}

