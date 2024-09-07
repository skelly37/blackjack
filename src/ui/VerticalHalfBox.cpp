#include "ui/VerticalHalfBox.hpp"

VerticalHalfBox::VerticalHalfBox(std::shared_ptr<Player> player,
                                 std::unique_ptr<PushButtonState> initial_button_state,
                                 QWidget *parent) : QVBoxLayout(parent), player(std::move(player)), button(std::move(initial_button_state)) {
    addWidget(&stats, 0, Qt::AlignHCenter);
    addStretch();
    addWidget(&cards, 0, Qt::AlignHCenter);
    addStretch();
    addWidget(&button);
}
