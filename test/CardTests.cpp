#include <gtest/gtest.h>

#include "cards/Card.hpp"

using namespace testing;

struct CardTests : public Test {};


TEST_F(CardTests, canCreate) {
    const Card::Symbol symbol = Card::Symbol::SIX;
    const Card::Color color = Card::Color::CLUBS;

    Card card{symbol, color};

    EXPECT_EQ(card.color, color);
    EXPECT_EQ(card.symbol, symbol);
    EXPECT_EQ(card.value, card.VALUES.at(symbol));
}

TEST_F(CardTests, canGenerateString) {
    const Card::Symbol symbol = Card::Symbol::TEN;
    const Card::Color color = Card::Color::CLUBS;

    Card card{symbol, color};

    EXPECT_EQ(card.to_string(), card.COLORS.at(color) + card.SYMBOLS.at(symbol));
}

TEST_F(CardTests, decreasesAceValue) {
    const Card::Symbol symbol = Card::Symbol::ACE;
    const Card::Color color = Card::Color::SPADES;

    Card card{symbol, color};

    ASSERT_EQ(card.value, 11);
    card.decreaseValueIfAce();
    ASSERT_EQ(card.value, 1);
    card.decreaseValueIfAce();
    ASSERT_EQ(card.value, 1);
}

TEST_F(CardTests, ignoresValueDecreaseIfNotAce) {
    const Card::Symbol symbol = Card::Symbol::JACK;
    const Card::Color color = Card::Color::DIAMONDS;

    Card card{symbol, color};

    ASSERT_EQ(card.value, card.VALUES.at(symbol));
    card.decreaseValueIfAce();
    ASSERT_EQ(card.value, card.VALUES.at(symbol));
}