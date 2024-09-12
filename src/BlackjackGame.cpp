#include "BlackjackGame.hpp"

#include <qcoreevent.h>
#include <player/Dealer.hpp>
#include <player/User.hpp>

#include "communication/GameStatus.hpp"

BlackjackGame::BlackjackGame(std::function<void()> updateUI) : updateUI(std::move(updateUI)), user(std::make_shared<User>()), dealer(std::make_shared<Dealer>()) {
}

void BlackjackGame::play(VerticalHalfBox *user_side, VerticalHalfBox *dealer_side) {
    this->user_side = user_side;
    this->dealer_side = dealer_side;

    if(this->user_side == nullptr || this->dealer_side == nullptr) {
        throw std::invalid_argument{"VerticalHalfBox cannot be null!"};
    }

    while (GameStatus::getStatus() == GameStatus::Status::START_REQUESTED) {
        gameLoop();
        while (GameStatus::getStatus() == GameStatus::Status::FINISHED) {}
    }
}

std::shared_ptr<Player> BlackjackGame::getUser() const {
    return user;
}

std::shared_ptr<Player> BlackjackGame::getDealer() const {
    return dealer;
}

void BlackjackGame::prepareRound() {
    if (deck.getCardsLeftCount() < 20) {
        deck.reshuffle();
    }

    for (std::size_t i = 0; i < 2; ++i) {
        user->addCard(deck.getCard());
        dealer->addCard(deck.getCard());
    }

    user_side->setAllCardsVisible();
    dealer_side->setOnlyFirstCardVisible();
}

void BlackjackGame::doMoves() {
    for (const std::shared_ptr<Player> &player: players) {
        if(!isAnyPlayerBusted()) {
            player->move(deck);
        }
    }
}

void BlackjackGame::showAllCards() {
    if(GameStatus::getStatus() != GameStatus::Status::STOP_REQUESTED) {
        GameStatus::finish();
    }

    user_side->setAllCardsVisible();
    dealer_side->setAllCardsVisible();
}

void BlackjackGame::finishRound() {
    if (user->getCurrentScore() == dealer->getCurrentScore()) {
        user_side->draw();
        dealer_side->draw();
    } else if (isUserWinner()) {
        user_side->win();
        dealer->lose();
    } else {
        user->lose();
        dealer_side->win();
    }
}

bool BlackjackGame::isUserWinner() const {
    return (user->getCurrentScore() > dealer->getCurrentScore() && user->getCurrentScore() <= Player::MAX_POINTS) ||
           dealer->getCurrentScore() > Player::MAX_POINTS;
}

bool BlackjackGame::isAnyPlayerBusted() const {
    return std::ranges::any_of(players, [](const std::shared_ptr<Player> &player) {
        return player->getCurrentScore() > Player::MAX_POINTS;
    });
}

bool BlackjackGame::doesAnyPlayerNeedToMove() const {
    return std::ranges::any_of(players, [](const std::shared_ptr<Player> &player) {
        return player->shouldMove();
    });
}

void BlackjackGame::gameLoop() {
    GameStatus::start();
    updateUI();

    prepareRound();
    updateUI();

    while (doesAnyPlayerNeedToMove() && !isAnyPlayerBusted()) {
        doMoves();
        updateUI();
    }

    showAllCards();
    updateUI();

    finishRound();
    updateUI();
}
