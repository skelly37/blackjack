#include "Player.hpp"

#include <boost/algorithm/string/trim.hpp>

#include <numeric>
#include <algorithm>

Player::Player(std::string &&name) : NAME(std::move(name)) {
}

void Player::addCard(Card &&card) {
    hand.emplace_back(std::move(card));
}

std::size_t Player::calculateScore() {
    std::size_t result = getCurrentScore();

    // handle ace downgrade from 11 to 1
    if (result > 21) {
        for(Card& card : hand) {
            card.decreaseValueIfAce();
        }
        result = getCurrentScore();
    }

    return result;
}

std::string Player::getHand() const {
    std::string result = std::accumulate(hand.begin(), hand.end(), std::string{""}, [](const std::string &acc, const Card &card) {
        return acc + card.to_string() + " ";
    });

    boost::algorithm::trim(result);
    return result;
}

std::size_t Player::getCurrentScore() const {
    return std::accumulate(hand.begin(), hand.end(), 0u, [](std::size_t acc, const Card &card) {
        return acc + card.value;
    });
}
