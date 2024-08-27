#include "game/UserDealerGame.hpp"
#include "player/User.hpp"
#include "player/Dealer.hpp"

#include <algorithm>


UserDealerGame::UserDealerGame(std::shared_ptr<IO> io, std::string &&username) : Game(io), user(std::make_shared<User>(io, std::move(username))),
    dealer(std::make_shared<Dealer>()),
    players({user, dealer}) {
}

void UserDealerGame::initializeGame() {
    if (deck.getCardsLeftCount() < 20) {
        deck.reshuffle();
    }
    for (std::size_t i = 0; i < 2; ++i) {
        user->addCard(deck.getCard());
        dealer->addCard(deck.getCard());
    }

    io->displayGameUIWithP2Hidden(user, dealer);
}

void UserDealerGame::hitAndStandLoop() {
    while (doesAnyPlayerNeedToMove() && !isAnyPlayerBusted()) {
        for (const std::shared_ptr<Player> &player: players) {
            io->displayGameUIWithP2Hidden(user, dealer);
            if (shouldPlayerMove(player)) {
                player->move(deck);
            }
        }
    }
}

void UserDealerGame::finalizeGame() {
    io->displayGameUIWithP2Visible(user, dealer);

    if (user->getCurrentScore() == dealer->getCurrentScore()) {
        user->draw();
        dealer->draw();
        io->displayDraw(user, dealer);
    } else if (
        (user->getCurrentScore() > dealer->getCurrentScore() && user->getCurrentScore() <= Player::MAX_POINTS) ||
        dealer->getCurrentScore() > Player::MAX_POINTS
        ) {
        user->win();
        dealer->lose();
        io->displayWin(user);
    } else {
        user->lose();
        dealer->win();
        io->displayWin(dealer);
    }
}

bool UserDealerGame::shouldPlayerMove(const std::shared_ptr<Player> &player) const {
    return player->shouldMove() && !isAnyPlayerBusted();
}

bool UserDealerGame::isAnyPlayerBusted() const {
    return std::ranges::any_of(players, [](const std::shared_ptr<Player> &player) {
        return player->getCurrentScore() > Player::MAX_POINTS;
    });
}

bool UserDealerGame::doesAnyPlayerNeedToMove() const {
    return std::ranges::any_of(players, [](const std::shared_ptr<Player> &player) {
        return player->shouldMove();
    });
}