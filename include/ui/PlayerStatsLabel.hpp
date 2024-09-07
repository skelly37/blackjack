#pragma once

#include "player/Player.hpp"

#include <QLabel>


class PlayerStatsLabel : public QLabel {
public:
    explicit PlayerStatsLabel(std::shared_ptr<Player> player, QWidget* parent = nullptr);

    void update();

private:
    [[nodiscard]] static QString generatePlayerLabel(const std::shared_ptr<Player>& player);

    std::shared_ptr<Player> player;
};