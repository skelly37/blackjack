#include "ui/GameWindow.hpp"
#include "communication/GameStatus.hpp"

#include <QMessageBox>


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

void GameWindow::play() {
    while (GameStatus::getStatus() == GameStatus::Status::START_REQUESTED) {
        gameLoop();
        while (GameStatus::getStatus() == GameStatus::Status::FINISHED) {
        }
    }
    close();
}

void GameWindow::closeEvent(QCloseEvent *event) {
    GameStatus::stop();
    QWidget::closeEvent(event);
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
            if(!isAnyPlayerBusted()) {
                player->move(deck);
            }
        }
        updateUI();
    }

    GameStatus::finish();
    left_side->setAllCardsVisible();
    right_side->setAllCardsVisible();
    updateUI();

    if (user->getCurrentScore() == dealer->getCurrentScore()) {
        user->draw();
        dealer->draw();
        QMetaObject::invokeMethod(this, [&] {
            QMessageBox(QMessageBox::NoIcon, "Draw", "Draw!").exec();
        });
    } else if (
        (user->getCurrentScore() > dealer->getCurrentScore() && user->getCurrentScore() <= Player::MAX_POINTS) ||
        dealer->getCurrentScore() > Player::MAX_POINTS
        ) {
        user->win();
        dealer->lose();
        QMetaObject::invokeMethod(this, [&] {
            QMessageBox(QMessageBox::NoIcon, "Win", "You have won!").exec();
        });
    } else {
        user->lose();
        dealer->win();
        QMetaObject::invokeMethod(this, [&] {
            QMessageBox(QMessageBox::NoIcon, "Lose", "You have lost!").exec();
        });
    }
    updateUI();
}

void GameWindow::updateUI() {
    QMetaObject::invokeMethod(this, [&] {
        left_side->updateState();
    }, Qt::BlockingQueuedConnection);
    QMetaObject::invokeMethod(this, [&] {
        right_side->updateState();
    }, Qt::BlockingQueuedConnection);
    QMetaObject::invokeMethod(this, [&] {
        update();
    }, Qt::BlockingQueuedConnection);
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
