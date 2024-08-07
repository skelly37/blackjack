#pragma once
#include "Card.hpp"

#include <vector>

class Player {
public:
    explicit Player(std::string &&name);

    void addCard(Card &&card);
    [[nodiscard]] std::size_t calculateScore();
    [[nodiscard]] std::string getHand() const;

    const std::string NAME;

private:
    [[nodiscard]] std::size_t getCurrentScore() const;

    std::vector<Card> hand;
};
