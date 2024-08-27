#include "UserDealerGame.hpp"
#include "User.hpp"
#include "Dealer.hpp"
#include "PrintHelpers.hpp"

#include <algorithm>


UserDealerGame::UserDealerGame(std::string &&username) : user(std::make_shared<User>(std::move(username))),
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
    print(user, dealer);
}

void UserDealerGame::hitAndStandLoop() {
    while (doesAnyPlayerNeedToMove() && !isAnyPlayerBusted()) {
        for (const std::shared_ptr<Player> &player: players) {
            print(user, dealer);
            if (shouldPlayerMove(player)) {
                player->move(deck);
            }
        }
    }
}

void UserDealerGame::finalizeGame() {
    print(user, dealer, false);

    if (user->getCurrentScore() == dealer->getCurrentScore()) {
        std::cout << "Draw!\n\n";
        user->draw();
        dealer->draw();
    } else if (
        (user->getCurrentScore() > dealer->getCurrentScore() && user->getCurrentScore() <= Player::MAX_POINTS) ||
        dealer->getCurrentScore() > Player::MAX_POINTS
        ) {
        std::cout << user->NAME << " wins!\n\n";
        user->win();
        dealer->lose();
    } else {
        std::cout << dealer->NAME << " wins!\n\n";
        user->lose();
        dealer->win();
    }

    std::cout << "Press Q to quit, any other key to play once again\n";
    std::cout << std::endl;
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