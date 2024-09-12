#include "ui/GameWindow.hpp"
#include "communication/GameStatus.hpp"

#include <QCloseEvent>


GameWindow::GameWindow(QWidget *parent) : QWidget(parent) {
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

std::jthread GameWindow::startGame() {
    return std::jthread([&] {
        game.play(left_side, right_side);
        close();
    });
}

void GameWindow::closeEvent(QCloseEvent *event) {
    GameStatus::stop();
    event->accept();
    GameStatus::stop();
}

void GameWindow::updateUI() {
    if(GameStatus::getStatus() == GameStatus::Status::STOP_REQUESTED) {
        return;
    }

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
