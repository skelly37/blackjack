#include "ui/VerticalHalfBox.hpp"

VerticalHalfBox::VerticalHalfBox(std::shared_ptr<Player> player,
                                 std::unique_ptr<PushButtonState> initial_button_state,
                                 QWidget *parent) : QVBoxLayout(parent), player(std::move(player)), button(new PushButton{std::move(initial_button_state)}) {
    addWidget(stats, 0, Qt::AlignHCenter);
    addStretch();
    addWidget(cards, 0, Qt::AlignHCenter);
    addStretch();
    addWidget(button);
}

void VerticalHalfBox::updateState() {
    stats->updateStats();
    cards->updateCards();
    button->setNextState();
}

void VerticalHalfBox::setAllCardsVisible() {
    cards->setAllCardsVisible();
}

void VerticalHalfBox::setOnlyFirstCardVisible() {
    cards->setOnlyFirstCardVisible();
}

void VerticalHalfBox::win() {
    player->win();
    cards->markWin();
}

void VerticalHalfBox::draw() {
    player->draw();
    cards->markDraw();
}
