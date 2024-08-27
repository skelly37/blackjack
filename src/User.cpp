#include "User.hpp"

#include <iostream>

User::User(std::string&& name) : Player(std::move(name)) {
}

void User::move(Deck &deck) {
    if (getUserChoice() == Choice::HIT) {
        addCard(deck.getCard());
    } else {
        stand();
    }
}

User::Choice User::getUserChoice() const {
    std::string input;
    while (true) {
        std::cout << "Turn of: " << NAME << "\n";
        std::cout << "Press H to hit, S to stand\n";
        std::getline(std::cin, input);

        if (input.empty()) {
            continue;
        }

        switch(tolower(input[0])) {
        case 'h':
            return Choice::HIT;
        case 's':
            return Choice::STAND;
        default:
            break;
        }
    }
}
