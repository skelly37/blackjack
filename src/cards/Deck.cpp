#include "cards/Deck.hpp"

#include <algorithm>
#include <random>
#include <ranges>


Deck::Deck(std::size_t amount_of_decks) : AMOUNT_OF_DECKS(amount_of_decks) {
    reshuffle();
}

Card Deck::getCard() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::size_t> dist(0, cards.size() - 1);

    const std::size_t idx = dist(rng);

    Card card = cards.at(idx);
    cards.erase(cards.begin() + idx);
    return card;
}

std::size_t Deck::getCardsLeftCount() const {
    return cards.size();
}

void Deck::reshuffle() {
    cards.clear();

    for (std::size_t i = 0; i < AMOUNT_OF_DECKS; ++i) {
        std::ranges::copy(SINGLE_DECK, std::back_inserter(cards));
    }
}

std::vector<Card> Deck::generateSingleDeck() {
    std::vector<Card> result;

    for (const Card::Color &color: std::ranges::views::keys(Card::COLORS)) {
        for (const Card::Symbol &symbol: std::ranges::views::keys(Card::SYMBOLS)) {
            result.emplace_back(symbol, color);
        }
    }

    return result;
}
