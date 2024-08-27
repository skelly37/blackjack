#include "cards/Card.hpp"

Card::Card(Card::Symbol symbol, Card::Color color) :
    value(VALUES.at(symbol)),
    symbol(symbol),
    color(color) {
}

std::string Card::to_string() const {
    return COLORS.at(color) + SYMBOLS.at(symbol) + (symbol == Symbol::TEN? "" : " ");
}

void Card::decreaseValueIfAce() {
    if(symbol == Symbol::ACE) {
        value = 1;
    }
}
