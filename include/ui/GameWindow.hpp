#pragma once

#include "ui/CardWidget.hpp"
#include "ui/VerticalHalfBox.hpp"
#include "ui/PushButton.hpp"
#include "ui/PlayerStatsLabel.hpp"

class GameWindow final : public QWidget {
public:
    GameWindow(std::shared_ptr<Player> user, std::shared_ptr<Player> dealer, QWidget *parent = nullptr);
    void gameLoop();

    static constexpr unsigned int WIDTH = 1000;
    static constexpr unsigned int HEIGHT = 600;
    static inline const QString TITLE = "Blackjack";

private:
    void updateUI();

    [[nodiscard]] bool isAnyPlayerBusted() const;
    [[nodiscard]] bool doesAnyPlayerNeedToMove() const;


    std::shared_ptr<Player> user;
    std::shared_ptr<Player> dealer;
    Deck deck;
    std::array<std::shared_ptr<Player>, 2> players {user, dealer};

    VerticalHalfBox* left_side = new VerticalHalfBox{user, std::make_unique<HitButtonState>()};
    VerticalHalfBox* right_side = new VerticalHalfBox{dealer, std::make_unique<StandButtonState>()};
    QHBoxLayout* main_layout = new QHBoxLayout;
};
