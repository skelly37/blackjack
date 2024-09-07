#pragma once

#include "ui/CardWidget.hpp"
#include "ui/VerticalHalfBox.hpp"
#include "ui/PushButton.hpp"
#include "ui/PlayerStatsLabel.hpp"

class GameWindow final : public QWidget {
public:
    GameWindow(std::shared_ptr<Player> user, std::shared_ptr<Player> dealer, QWidget *parent = nullptr);

    static constexpr unsigned int WIDTH = 1000;
    static constexpr unsigned int HEIGHT = 600;
    static inline const QString* TITLE = new QString{"Blackjack"};

private:
    std::shared_ptr<Player> user;
    std::shared_ptr<Player> dealer;

    VerticalHalfBox* left_side = new VerticalHalfBox{user, std::make_unique<HitButtonState>()};
    VerticalHalfBox* right_side = new VerticalHalfBox{dealer, std::make_unique<StandButtonState>()};
    QHBoxLayout* main_layout = new QHBoxLayout;
};
