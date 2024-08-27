#pragma once
#include "Card.hpp"
#include "Deck.hpp"

#include <vector>

class Player {
public:
    explicit Player(std::string &&name);
    virtual ~Player() = default;

    virtual void move(Deck& deck) = 0;
    void addCard(Card &&card);
    void stand();
    [[nodiscard]] bool shouldMove() const;
    [[nodiscard]] std::size_t getCurrentScore() const;
    [[nodiscard]] std::string getHand() const;
    [[nodiscard]] Card getFirstCard() const;
    [[nodiscard]] std::size_t getCardsCount() const;
    [[nodiscard]] std::size_t getPlayedGames() const;
    [[nodiscard]] std::size_t getWins() const;
    [[nodiscard]] std::size_t getDraws() const;
    [[nodiscard]] std::string getWinsDrawsTotalFormattedString() const;

    void win();
    void draw();
    void lose();

    const std::string NAME;
    static constexpr std::size_t MAX_POINTS = 21;

private:
    void clear();
    void updateScore();

    std::vector<Card> hand;
    bool does_need_next_move = true;
    std::size_t total_games = 0;
    std::size_t wins = 0;
    std::size_t draws = 0;
};

