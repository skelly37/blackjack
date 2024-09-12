#pragma once

#include "ui/VerticalHalfBox.hpp"
#include "BlackjackGame.hpp"

#include <thread>

class GameWindow final : public QWidget {
public:
    explicit GameWindow(QWidget *parent = nullptr);
    std::jthread startGame();

    static constexpr unsigned int WIDTH = 1000;
    static constexpr unsigned int HEIGHT = 600;
    static inline const QString TITLE = "Blackjack";

private:
    void closeEvent(QCloseEvent *event) override;
    void updateUI();

    BlackjackGame game{[&] {
                           updateUI();
                       }};

    VerticalHalfBox* left_side = new VerticalHalfBox{game.getUser(), std::make_unique<HitButtonState>()};
    VerticalHalfBox* right_side = new VerticalHalfBox{game.getDealer(), std::make_unique<StandButtonState>()};
    QHBoxLayout* main_layout = new QHBoxLayout;
};
