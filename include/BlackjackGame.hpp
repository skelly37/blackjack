#pragma once

#include "cards/Deck.hpp"
#include "ui/VerticalHalfBox.hpp"

class BlackjackGame {
public:
    explicit BlackjackGame(std::function<void()> updateUI);
    void play(VerticalHalfBox* user_side, VerticalHalfBox* dealer_side);

    [[nodiscard]] std::shared_ptr<Player> getUser() const;
    [[nodiscard]] std::shared_ptr<Player> getDealer() const;

private:
    void gameLoop();
    void prepareRound();
    void doMoves();
    void showAllCards();
    void finishRound();

    [[nodiscard]] bool isUserWinner() const;
    [[nodiscard]] bool isAnyPlayerBusted() const;
    [[nodiscard]] bool doesAnyPlayerNeedToMove() const;

    std::shared_ptr<Player> user;
    std::shared_ptr<Player> dealer;
    std::array<std::shared_ptr<Player>, 2> players {user, dealer};
    Deck deck;
    std::function<void()> updateUI;

    VerticalHalfBox* user_side = nullptr;
    VerticalHalfBox* dealer_side = nullptr;
};