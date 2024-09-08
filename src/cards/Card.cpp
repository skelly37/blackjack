#include "cards/Card.hpp"

Card::Card(Symbol symbol, Color color) : value(VALUES.at(symbol)), symbol(symbol), color(color) {
}

bool Card::operator== (const Card& other) const {
    return this->symbol == other.symbol && this->color == other.color;
}

void Card::decreaseValueIfAce() {
    if(symbol == Symbol::ACE) {
        value = 1;
    }
}
