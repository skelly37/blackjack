#include "ui/GameWindow.hpp"
#include "communication/GameStatus.hpp"


GameWindow::GameWindow(std::shared_ptr<Player> user, std::shared_ptr<Player> dealer, QWidget *parent) : QWidget(parent),
    user(std::move(
             user)),
    dealer(
        std::move(
            dealer)) {
    setWindowTitle(TITLE);
    resize(WIDTH, HEIGHT);

    main_layout->addLayout(left_side);
    main_layout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    main_layout->addLayout(right_side);

    setLayout(main_layout);
    setStyleSheet("");
    setStyleSheet("QWidget { background-color: beige; }");
    update();
    show();
}

void GameWindow::gameLoop() {
    GameStatus::start();

    if (deck.getCardsLeftCount() < 20) {
        deck.reshuffle();
    }

    for (std::size_t i = 0; i < 2; ++i) {
        user->addCard(deck.getCard());
        dealer->addCard(deck.getCard());
    }

    left_side->setAllCardsVisible();
    right_side->setOnlyFirstCardVisible();
    updateUI();

    while (doesAnyPlayerNeedToMove() && !isAnyPlayerBusted()) {
        for (const std::shared_ptr<Player> &player: players) {
            player->move(deck);
        }
        updateUI();
    }

    GameStatus::finish();
}

void GameWindow::updateUI() {
    left_side->updateState();
    right_side->updateState();
}

bool GameWindow::isAnyPlayerBusted() const {
    return std::ranges::any_of(players, [](const std::shared_ptr<Player> &player) {
        return player->getCurrentScore() > Player::MAX_POINTS;
    });
}

bool GameWindow::doesAnyPlayerNeedToMove() const {
    return std::ranges::any_of(players, [](const std::shared_ptr<Player> &player) {
        return player->shouldMove();
    });
}


/*

   void UserDealerGame::hitAndStandLoop() {

   }

   void UserDealerGame::finalizeGame() {
   //io->displayGameUIWithP2Visible(user, dealer);

   if (user->getCurrentScore() == dealer->getCurrentScore()) {
   user->draw();
   dealer->draw();
   //io->displayDraw(user, dealer);
   } else if (
   (user->getCurrentScore() > dealer->getCurrentScore() && user->getCurrentScore() <= Player::MAX_POINTS) ||
   dealer->getCurrentScore() > Player::MAX_POINTS
   ) {
   user->win();
   dealer->lose();
   //io->displayWin(user);
   } else {
   user->lose();
   dealer->win();
   //io->displayWin(dealer);
   }
   }
 */
