#include <gtest/gtest.h>

#include "player/User.hpp"
#include "StubIO.hpp"

using namespace testing;

// Also contains generic Player tests (abstract class anyway)
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

    const std::vector<Card> &hand = user.getHand();

    ASSERT_EQ(hand.size(), 1);
    ASSERT_EQ(hand.at(0), card);
    ASSERT_EQ(user.getCurrentScore(), Card::VALUES.at(card.symbol));
    ASSERT_TRUE(user.shouldMove());
}

TEST_F(UserTests, canGetFirstCard) {
    user.addCard(deck.getCard());

    const std::vector<Card> &hand = user.getHand();
    ASSERT_FALSE(hand.empty());
    ASSERT_EQ(hand.at(0), user.getFirstCard());
}

TEST_F(UserTests, canGetCardsCount) {
    ASSERT_TRUE(user.getHand().empty());
    ASSERT_EQ(user.getCardsCount(), 0);

    user.addCard(deck.getCard());

    ASSERT_FALSE(user.getHand().empty());
    ASSERT_EQ(user.getCardsCount(), 1);
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

    user.addCard(Card{Card::Symbol::TEN, Card::Color::HEARTS});
    ASSERT_LT(user.getCurrentScore(), Player::MAX_POINTS);
    ASSERT_TRUE(user.shouldMove());

    user.addCard(Card{Card::Symbol::TEN, Card::Color::HEARTS});
    ASSERT_LT(user.getCurrentScore(), Player::MAX_POINTS);
    ASSERT_TRUE(user.shouldMove());

    user.addCard(Card{Card::Symbol::TEN, Card::Color::HEARTS});
    ASSERT_GT(user.getCurrentScore(), Player::MAX_POINTS);
    ASSERT_FALSE(user.shouldMove());
}

TEST_F(UserTests, shouldNotMoveWhenStood) {
    ASSERT_TRUE(user.shouldMove());

    user.move(deck);
    ASSERT_TRUE(user.shouldMove());
    ASSERT_GT(user.getCardsCount(), 0);

    user.stand();
    user.move(deck);
    ASSERT_FALSE(user.shouldMove());
    ASSERT_GT(user.getCardsCount(), 0);
}

TEST_F(UserTests, canWin) {
    user.addCard(deck.getCard());
    ASSERT_EQ(user.getCardsCount(), 1);
    ASSERT_GT(user.getCurrentScore(), 0);

    user.win();
    ASSERT_EQ(user.getCardsCount(), 0);
    ASSERT_EQ(user.getCurrentScore(), 0);
    ASSERT_EQ(user.getPlayedGames(), 1);
    ASSERT_EQ(user.getWins(), 1);
}

TEST_F(UserTests, canDraw) {
    user.addCard(deck.getCard());
    ASSERT_EQ(user.getCardsCount(), 1);
    ASSERT_GT(user.getCurrentScore(), 0);

    user.draw();
    ASSERT_EQ(user.getCardsCount(), 0);
    ASSERT_EQ(user.getCurrentScore(), 0);
    ASSERT_EQ(user.getPlayedGames(), 1);
    ASSERT_EQ(user.getDraws(), 1);
}

TEST_F(UserTests, canLose) {
    user.addCard(deck.getCard());
    ASSERT_EQ(user.getCardsCount(), 1);
    ASSERT_GT(user.getCurrentScore(), 0);

    user.lose();
    ASSERT_EQ(user.getCardsCount(), 0);
    ASSERT_EQ(user.getCurrentScore(), 0);
    ASSERT_EQ(user.getPlayedGames(), 1);
}
