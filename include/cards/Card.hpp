#pragma once

#include <string>
#include <unordered_map>


struct Card {
    enum class Color {
        HEARTS,
        SPADES,
        CLUBS,
        DIAMONDS,
    };

    enum class Symbol {
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE,
    };

    static inline const std::unordered_map<Color, std::string> COLORS{
        {Color::HEARTS, "♥"},
        {Color::SPADES, "♠"},
        {Color::CLUBS, "♣"},
        {Color::DIAMONDS, "♦"},
    };

    static inline const std::unordered_map<Symbol, std::string> SYMBOLS{
        {Symbol::TWO, "2 "},
        {Symbol::THREE, "3 "},
        {Symbol::FOUR, "4 "},
        {Symbol::FIVE, "5 "},
        {Symbol::SIX, "6 "},
        {Symbol::SEVEN, "7 "},
        {Symbol::EIGHT, "8 "},
        {Symbol::NINE, "9 "},
        {Symbol::TEN, "10"},
        {Symbol::JACK, "J "},
        {Symbol::QUEEN, "Q "},
        {Symbol::KING, "K "},
        {Symbol::ACE, "A "},
    };

    static inline const std::unordered_map<Symbol, std::size_t> VALUES{
        {Symbol::TWO, 2},
        {Symbol::THREE, 3},
        {Symbol::FOUR, 4},
        {Symbol::FIVE, 5},
        {Symbol::SIX, 6},
        {Symbol::SEVEN, 7},
        {Symbol::EIGHT, 8},
        {Symbol::NINE, 9},
        {Symbol::TEN, 10},
        {Symbol::JACK, 10},
        {Symbol::QUEEN, 10},
        {Symbol::KING, 10},
        {Symbol::ACE, 11},
    };

    std::size_t value;
    Symbol symbol;
    Color color;

    Card(Symbol symbol, Color color);
    bool operator==(const Card& other) const;

    [[nodiscard]] std::string to_string() const;
    void decreaseValueIfAce();
};
