#pragma once
#include "cards/Card.hpp"
#include "cards/Deck.hpp"

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
    [[nodiscard]] const std::vector<Card>& getHand() const;
    [[nodiscard]] Card getFirstCard() const;
    [[nodiscard]] std::size_t getCardsCount() const;
    [[nodiscard]] std::size_t getPlayedGames() const;
    [[nodiscard]] std::size_t getWins() const;
    [[nodiscard]] std::size_t getDraws() const;

    void win();
    void draw();
    void lose();

    [[nodiscard]] virtual std::size_t getAmountOfPointsToForceStand() const = 0;

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

