#include "player/Player.hpp"

#include <numeric>

Player::Player(std::string &&name) : NAME(std::move(name)) {
}

void Player::addCard(Card &&card) {
    hand.emplace_back(card);
    updateScore();
}

void Player::stand() {
    does_need_next_move = false;
}

bool Player::shouldMove() const {
    return does_need_next_move;
}

void Player::updateScore() {
    if (getCurrentScore() > MAX_POINTS) {
        for(Card& card : hand) {
            card.decreaseValueIfAce();
        }
    }

    if (getCurrentScore() >= getAmountOfPointsToForceStand()) {
        does_need_next_move = false;
    }
}

const std::vector<Card>& Player::getHand() const {
    return hand;
}

Card Player::getFirstCard() const {
    Card card = hand.at(0);

    if(card.value == 1) {
        card.value = 11;
    }

    return card;
}

std::size_t Player::getCardsCount() const {
    return hand.size();
}

void Player::clear() {
    hand.clear();
    does_need_next_move = true;
}


std::size_t Player::getCurrentScore() const {
    return std::accumulate(hand.begin(), hand.end(), 0u, [](std::size_t acc, const Card &card) {
        return acc + card.value;
    });
}


std::size_t Player::getDraws() const {
    return draws;
}

void Player::draw() {
    ++total_games;
    ++draws;
    clear();
}

std::size_t Player::getPlayedGames() const {
    return total_games;
}

std::size_t Player::getWins() const {
    return wins;
}

void Player::win() {
    ++total_games;
    ++wins;
    clear();
}

void Player::lose() {
    ++total_games;
    clear();
}