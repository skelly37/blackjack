#include "ui/PlayerStatsLabel.hpp"

#include <fmt/format.h>

PlayerStatsLabel::PlayerStatsLabel(std::shared_ptr<Player> player, QWidget* parent) : QLabel(generatePlayerLabel(player), parent), player(std::move(player)) {
    setAlignment(Qt::AlignCenter);
    setStyleSheet("");
    setStyleSheet("QLabel { color : black; font-size: 16px; }");
    update();
}

void PlayerStatsLabel::updateStats() {
    setText(generatePlayerLabel(player));
}

QString PlayerStatsLabel::generatePlayerLabel(const std::shared_ptr<Player>& player) {
    return QString{
        fmt::format(
            "{} (W: {} | D: {} | T: {})",
            player->NAME, player->getWins(), player->getDraws(), player->getPlayedGames()
            ).c_str()
    };
}