#include "ui/CardsGrid.hpp"
#include "communication/GameStatus.hpp"
#include "cards/Card.hpp"


CardsGrid::CardsGrid(std::shared_ptr<Player> player, std::size_t rows, std::size_t cols, QWidget* parent) : QWidget(parent), player(std::move(player)), ROWS(rows), COLS(cols){
    total_points->setStyleSheet("QLabel {color: black; font-size: 30px; font-weight: bold}");
    maybe_status_text->setStyleSheet("QLabel {color: black; font-size: 40px; font-weight: bold}");

    for(std::size_t i = 0; i < ROWS; ++i) {
        for(std::size_t j = 0; j < COLS; ++j) {
            if(j == 0) {
                hand.emplace_back();
            }
            hand[i].emplace_back(new CardWidget);

            cards_grid->addWidget(hand[i][j], i, j);
        }
    }

    cards_grid->addWidget(total_points, ROWS, 0, 1, 5, Qt::AlignCenter);
    cards_grid->addWidget(maybe_status_text, ROWS+1, 0, 1, 5, Qt::AlignCenter);

    cards_grid->setHorizontalSpacing(10);
    cards_grid->setVerticalSpacing(10);
    cards_grid->addItem(new QSpacerItem(10, 20), 0, 5);
    cards_grid->setColumnStretch(0, 1);
    cards_grid->setColumnStretch(5, 1);

    setLayout(cards_grid);
}

void CardsGrid::updateCards() {
    if(is_win or is_draw) {
        if(GameStatus::getStatus() == GameStatus::Status::FINISHED) {
            maybe_status_text->setText(is_win? "WINNER" : "DRAW");
        } else {
            maybe_status_text->setText("");
            is_win = false;
            is_draw = false;
        }
    }

    if(player->getHand().empty()) {
        return;
    }

    updateCardsGrid();
    updateTotalPoints(are_all_cards_visible? player->getCurrentScore() : player->getFirstCard().value);
}

void CardsGrid::setAllCardsVisible() {
    are_all_cards_visible = true;
}

void CardsGrid::setOnlyFirstCardVisible() {
    are_all_cards_visible = false;
}

void CardsGrid::markWin() {
    is_win = true;
}

void CardsGrid::markDraw() {
    is_draw = true;
}

void CardsGrid::updateCardsGrid() {
    for(std::size_t i = 0; i < ROWS; ++i) {
        for(std::size_t j = 0; j < COLS; ++j) {
            hand[i][j]->setNoCardText();
            hand[i][j]->setNoCardBackground();
        }
    }

    const std::vector<Card>& player_hand = player->getHand();

    std::size_t current_hand_idx = 0;
    if (are_all_cards_visible) {
        for(std::size_t i = 0; i < ROWS; ++i) {
            for(std::size_t j = 0; j < COLS && current_hand_idx < player_hand.size(); ++j, ++current_hand_idx) {
                hand[i][j]->setCardText(player_hand.at(current_hand_idx).symbol);
                hand[i][j]->setBackground(player_hand.at(current_hand_idx).color);
            }
        }
    } else {
        for(std::size_t i = 0; i < ROWS; ++i) {
            for(std::size_t j = 0; j < COLS && current_hand_idx < player_hand.size(); ++j, ++current_hand_idx) {
                hand[i][j]->setNoCardText();
                hand[i][j]->setCardBackBackground();
            }
        }
        hand[0][0]->setCardText(player_hand.at(0).symbol);
        hand[0][0]->setBackground(player_hand.at(0).color);
    }
}

void CardsGrid::updateTotalPoints(std::size_t points) {
    total_points->setText(std::to_string(points).c_str());
}
