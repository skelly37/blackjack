#pragma once

#include "cards/Card.hpp"

#include <QFrame>

#include <filesystem>

namespace CardAssets {
static inline const std::filesystem::path& BACK {"back.png"};
static inline const std::filesystem::path& CLUBS {"clubs.png"};
static inline const std::filesystem::path& DIAMONDS {"diamonds.png"};
static inline const std::filesystem::path& EMPTY {"empty.png"};
static inline const std::filesystem::path& HEARTS {"hearts.png"};
static inline const std::filesystem::path& SPADES {"spades.png"};
}

class CardWidget final : public QFrame {
public:
    explicit CardWidget(QString value = "", QWidget *parent = nullptr);

    void setBackground(Card::Color color);
    void setCardBackBackground();
    void setNoCardBackground();

    void setCardText(Card::Symbol symbol);
    void setNoCardText();

private:
    void setBackground(const std::filesystem::path& path);
    void paintEvent(QPaintEvent *event) override;

    static inline const std::unordered_map<Card::Color, std::filesystem::path> COLOR_ASSETS {
        {Card::Color::CLUBS, CardAssets::CLUBS},
        {Card::Color::DIAMONDS, CardAssets::DIAMONDS},
        {Card::Color::HEARTS, CardAssets::HEARTS},
        {Card::Color::SPADES, CardAssets::SPADES},
    };

    QString value;
};