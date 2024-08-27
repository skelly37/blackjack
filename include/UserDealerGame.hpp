#pragma once

#include "Game.hpp"
#include "Deck.hpp"
#include "Player.hpp"

#include <memory>

class UserDealerGame : public Game {
public:
    explicit UserDealerGame(std::string&& username = "User");

private:
    void initializeGame() override;
    void hitAndStandLoop() override;
    void finalizeGame() override;
    [[nodiscard]] bool shouldPlayerMove(const std::shared_ptr<Player>& player) const;

    Deck deck;
    std::shared_ptr<Player> user;
    std::shared_ptr<Player> dealer;
    std::array<std::shared_ptr<Player>, 2> players;
};