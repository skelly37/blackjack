#pragma once

#include "ui/CardWidget.hpp"
#include "player/Player.hpp"

#include <QGridLayout>
#include <QLabel>

class CardsGrid final : public QWidget {
public:
    CardsGrid(std::shared_ptr<Player> player, std::size_t rows, std::size_t cols, QWidget* parent = nullptr);

    void updateCards();
    void setAllCardsVisible();
    void setOnlyFirstCardVisible();
    void markWin();
    void markDraw();

private:
    void updateCardsGrid();
    void updateTotalPoints(std::size_t points);

    std::shared_ptr<Player> player;
    const std::size_t ROWS;
    const std::size_t COLS;
    bool are_all_cards_visible = false;
    bool is_win = false;
    bool is_draw = false;

    std::vector<std::vector<CardWidget*> > hand;
    QLabel* total_points = new QLabel{"0"};
    QLabel* maybe_status_text = new QLabel{""};
    QGridLayout* cards_grid = new QGridLayout;
};
