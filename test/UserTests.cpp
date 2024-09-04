#include <gtest/gtest.h>

#include "player/User.hpp"
#include "StubIO.hpp"

using namespace testing;

struct UserTests : public Test {
    IO::UserChoice current_choice = IO::UserChoice::HIT;
    std::function<IO::UserChoice()> user_choice_getter = [&] {
                                                             return current_choice;
                                                         };
    std::shared_ptr<StubIO> io = std::make_shared<StubIO>(user_choice_getter);

    User user{io, "test_user"};
    Deck deck;
};

TEST_F(UserTests, handlesHit) {
    ASSERT_TRUE(user.getHand().empty());
    ASSERT_EQ(user.getCurrentScore(), 0);
    ASSERT_TRUE(user.shouldMove());

    Card card{Card::Symbol::TEN, Card::Color::HEARTS};
    user.addCard(std::move(card));

    const std::vector<Card>& hand = user.getHand();

    ASSERT_EQ(hand.size(), 1);
    ASSERT_EQ(hand.at(0), card);
    ASSERT_EQ(user.getCurrentScore(), Card::VALUES.at(card.symbol));
    ASSERT_TRUE(user.shouldMove());
}

TEST_F(UserTests, handlesStand) {
    ASSERT_TRUE(user.getHand().empty());
    ASSERT_EQ(user.getCurrentScore(), 0);
    ASSERT_TRUE(user.shouldMove());

    user.stand();

    ASSERT_TRUE(user.getHand().empty());
    ASSERT_EQ(user.getCurrentScore(), 0);
    ASSERT_FALSE(user.shouldMove());
}

TEST_F(UserTests, shouldNotMoveWhenBusted) {
    ASSERT_TRUE(user.shouldMove());
    user.addCard(Card {Card::Symbol::TEN, Card::Color::HEARTS});

    ASSERT_TRUE(user.shouldMove());
    user.addCard(Card {Card::Symbol::TEN, Card::Color::HEARTS});

    ASSERT_TRUE(user.shouldMove());
    user.addCard(Card {Card::Symbol::TEN, Card::Color::HEARTS});

    ASSERT_FALSE(user.shouldMove());
    ASSERT_GT(user.getCurrentScore(), Player::MAX_POINTS);
}