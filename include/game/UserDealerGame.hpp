#pragma once

#include "game/Game.hpp"
#include "cards/Deck.hpp"
#include "player/Player.hpp"


class UserDealerGame : public Game {
public:
    explicit UserDealerGame(std::shared_ptr<IO> io, std::string&& username = "User");

private:
    void initializeGame() override;
    void hitAndStandLoop() override;
    void finalizeGame() override;

    [[nodiscard]] bool shouldPlayerMove(const std::shared_ptr<Player>& player) const;
    [[nodiscard]] bool isAnyPlayerBusted() const;
    [[nodiscard]] bool doesAnyPlayerNeedToMove() const;

    Deck deck;
    std::shared_ptr<Player> user;
    std::shared_ptr<Player> dealer;
    std::array<std::shared_ptr<Player>, 2> players;
};