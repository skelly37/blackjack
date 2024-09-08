#include <gtest/gtest.h>

#include "player/Dealer.hpp"

using namespace testing;

// Only Dealer, Player functionality is tested in UserTests
struct DealerTests : public Test {
    Dealer dealer;
    Deck deck;
};

TEST_F(DealerTests, canHitUpTo17) {
    ASSERT_TRUE(dealer.shouldMove());

    dealer.addCard(Card{Card::Symbol::TEN, Card::Color::HEARTS});
    ASSERT_TRUE(dealer.shouldMove());

    dealer.addCard(Card{Card::Symbol::SIX, Card::Color::HEARTS});
    ASSERT_TRUE(dealer.shouldMove());

    dealer.addCard(Card{Card::Symbol::TWO, Card::Color::HEARTS});
    ASSERT_FALSE(dealer.shouldMove());

    dealer.move(deck);
    ASSERT_FALSE(dealer.shouldMove());
    ASSERT_EQ(dealer.getCardsCount(), 3);
}

