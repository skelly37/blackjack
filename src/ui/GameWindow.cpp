#include "ui/GameWindow.hpp"

#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

GameWindow::GameWindow(std::shared_ptr<Player> user, std::shared_ptr<Player> dealer, QWidget *parent) : QWidget(parent), user(std::move(user)), dealer(std::move(dealer)) {
    setWindowTitle(TITLE);
    resize(WIDTH, HEIGHT);

    main_layout->addLayout(left_side);
    main_layout->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    main_layout->addLayout(right_side);

    setLayout(main_layout);
    setStyleSheet("QWidget { background-color: beige; }");
    show();
}
