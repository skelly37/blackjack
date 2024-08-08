#pragma once
#include "Card.hpp"

#include <vector>

class Player {
public:
    explicit Player(std::string &&name);

    void addCard(Card &&card);
    void stand();
    [[nodiscard]] bool shouldMove() const;
    [[nodiscard]] std::size_t getCurrentScore() const;
    [[nodiscard]] std::string getHand() const;
    [[nodiscard]] std::string getFirstCard() const;
    [[nodiscard]] std::size_t getCardsCount() const;
    [[nodiscard]] std::size_t getPlayedGames() const;
    [[nodiscard]] std::size_t getWins() const;
    [[nodiscard]] std::size_t getDraws() const;
    [[nodiscard]] std::string getWinsDrawsTotalFormattedString() const;

    void win();
    void draw();
    void lose();

    const std::string NAME;

private:
    void clear();
    void updateScore();

    std::vector<Card> hand;
    bool does_need_next_move = true;
    std::size_t total_games = 0;
    std::size_t wins = 0;
    std::size_t draws = 0;
};

