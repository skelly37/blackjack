#pragma once

#include <QVBoxLayout>

#include "ui/PlayerStatsLabel.hpp"
#include "ui/CardsGrid.hpp"
#include "ui/PushButton.hpp"

class VerticalHalfBox : public QVBoxLayout {
public:
    VerticalHalfBox(std::shared_ptr<Player> player, std::unique_ptr<PushButtonState> initial_button_state, QWidget *parent = nullptr);

private:
    static constexpr std::size_t CARD_ROWS = 2;
    static constexpr std::size_t CARD_COLS = 5;

    std::shared_ptr<Player> player;

    PlayerStatsLabel stats {player};
    CardsGrid cards {CARD_ROWS, CARD_COLS};
    PushButton button;
};
