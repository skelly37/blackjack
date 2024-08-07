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

    ASSERT_EQ(player.calculateScore(), 10);
    ASSERT_EQ(player.getHand(), card_str);
}
