#pragma once

#include "CardWidget.hpp"

#include <QGridLayout>
#include <QLabel>

class CardsGrid final : public QWidget {
public:
    CardsGrid(std::size_t rows, std::size_t cols, QWidget* parent = nullptr);

    void updateTotalPoints(std::size_t points);

private:
    const std::size_t ROWS;
    const std::size_t COLS;

    std::vector<std::vector<CardWidget*> > hand;
    QLabel* total_points = new QLabel{"0"};
    QGridLayout* cards_grid = new QGridLayout;
};
