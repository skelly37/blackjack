#include <gtest/gtest.h>

#include "Player.hpp"

using namespace testing;

struct PlayerTests : public Test {
    Player player{"test_player"};
};

TEST_F(PlayerTests, handlesNewCard) {
    Card card{Card::Symbol::TEN, Card::Color::HEARTS};
    const std::string card_str = card.to_string();
    player.addCard(std::move(card));

    ASSERT_EQ(player.updateScore(), 10);
    ASSERT_EQ(player.getHand(), card_str);
}

TEST_F(PlayerTests, canBeCleared) {
    player.addCard(Card{Card::Symbol::TEN, Card::Color::HEARTS});

    ASSERT_GT(player.updateScore(), 0);
    ASSERT_NE(player.getHand(), "");

    player.clear();

    ASSERT_EQ(player.updateScore(), 0);
    ASSERT_EQ(player.getHand(), "");
}
