#include "ui/CardsGrid.hpp"
#include "cards/Card.hpp"


CardsGrid::CardsGrid(std::size_t rows, std::size_t cols, QWidget* parent) : QWidget(parent), ROWS(rows), COLS(cols){
    total_points.setStyleSheet("QLabel {color: black; font-size: 20px; font-weight: bold}");

    for(std::size_t i = 0; i < ROWS; ++i) {
        for(std::size_t j = 0; j < COLS; ++j) {
            if(j == 0) {
                hand.emplace_back();
            }
            hand[i].emplace_back(std::make_unique<CardWidget>());

            cards_grid.addWidget(hand[i][j].get(), i, j);
        }
    }

    cards_grid.addWidget(&total_points, 2, 0, 1, 5, Qt::AlignCenter);

    cards_grid.setHorizontalSpacing(10);
    cards_grid.setVerticalSpacing(10);
    cards_grid.addItem(new QSpacerItem(10, 20), 0, 5);
    cards_grid.setColumnStretch(0, 1);
    cards_grid.setColumnStretch(5, 1);

    setLayout(&cards_grid);
}

void CardsGrid::updateTotalPoints(std::size_t points) {
    total_points.setText(std::to_string(points).c_str());
}
