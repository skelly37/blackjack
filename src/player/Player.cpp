#include "player/Player.hpp"

#include <boost/algorithm/string/trim.hpp>
#include <fmt/format.h>

#include <numeric>
#include <algorithm>

Player::Player(std::string &&name) : NAME(std::move(name)) {
}

void Player::addCard(Card &&card) {
    hand.emplace_back(std::move(card));
    updateScore();
}

void Player::stand() {
    does_need_next_move = false;
}

bool Player::shouldMove() const {
    return does_need_next_move;
}

void Player::updateScore() {
    std::size_t result = getCurrentScore();

    // handle ace downgrade from 11 to 1 and bust
    if (result > MAX_POINTS) {
        for(Card& card : hand) {
            card.decreaseValueIfAce();
        }

        if (getCurrentScore() > MAX_POINTS) {
            does_need_next_move = false;
        }
    }
}

std::string Player::getHand() const {
    std::string result = std::accumulate(hand.begin(), hand.end(), std::string{""}, [](const std::string &acc, const Card &card) {
        return acc + card.to_string() + " ";
    });

    boost::algorithm::trim(result);
    return result;
}

Card Player::getFirstCard() const {
    Card card = hand.at(0);

    // hide info about ace becoming 11
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

std::string Player::getWinsDrawsTotalFormattedString() const {
    return fmt::format("{}/{}/{}", getWins(), getDraws(), getPlayedGames());
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