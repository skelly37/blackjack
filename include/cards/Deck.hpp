#pragma once

#include "cards/Card.hpp"

#include <vector>

class Deck {
public:
    explicit Deck(std::size_t amount_of_decks=1);

    [[nodiscard]] Card getCard();
    [[nodiscard]] std::size_t getCardsLeftCount() const;
    void reshuffle();

private:
    [[nodiscard]] static std::vector<Card> generateSingleDeck();

    const std::vector<Card> SINGLE_DECK = generateSingleDeck();
    const std::size_t AMOUNT_OF_DECKS;
    std::vector<Card> cards;
};