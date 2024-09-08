#pragma once

#include <QVBoxLayout>

#include "ui/PlayerStatsLabel.hpp"
#include "ui/CardsGrid.hpp"
#include "ui/PushButton.hpp"

class VerticalHalfBox final : public QVBoxLayout {
public:
    VerticalHalfBox(std::shared_ptr<Player> player, std::unique_ptr<PushButtonState> initial_button_state, QWidget *parent = nullptr);

    void updateState();
    void setAllCardsVisible();
    void setOnlyFirstCardVisible();

private:
    static constexpr std::size_t CARD_ROWS = 2;
    static constexpr std::size_t CARD_COLS = 5;

    std::shared_ptr<Player> player;

    PlayerStatsLabel* stats = new PlayerStatsLabel{player};
    CardsGrid* cards = new CardsGrid{player, CARD_ROWS, CARD_COLS};
    PushButton* button;
};
