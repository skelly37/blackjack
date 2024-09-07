#pragma once
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

class CardWidget : public QFrame {
public:
    explicit CardWidget(QString value = "", QWidget *parent = nullptr);

    void setBackground(const std::filesystem::path& image);

private:
    void paintEvent(QPaintEvent *event) override;

    QString value;
};