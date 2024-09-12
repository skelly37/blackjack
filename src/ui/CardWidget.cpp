#include "ui/CardWidget.hpp"

#include <QPainter>
#include <fmt/format.h>
#include <boost/algorithm/string.hpp>

CardWidget::CardWidget(QString value, QWidget *parent) : QFrame(parent), value(std::move(value)) {
    setFrameStyle(Panel | Sunken);
    setLineWidth(2);
    setFixedSize(77, 92);
    setBackground(CardAssets::EMPTY);
}

void CardWidget::setBackground(Card::Color color) {
    setBackground(COLOR_ASSETS.at(color));
}

void CardWidget::setCardBackBackground() {
    setBackground(CardAssets::BACK);
}

void CardWidget::setNoCardBackground() {
    setBackground(CardAssets::EMPTY);
}

void CardWidget::setCardText(Card::Symbol symbol) {
    std::string text = Card::SYMBOLS.at(symbol);
    boost::algorithm::trim(text);
    this->value = text.c_str();
}

void CardWidget::setNoCardText() {
    this->value = "";
}

void CardWidget::setBackground(const std::filesystem::path &image) {
    const std::string image_path = ASSETS_DIR / image;
    const QString style_sheet = QString::fromStdString(
        fmt::format(
            "QFrame {{ background-image: url({}); color: orange; border: 1px solid black; }}", image_path
            ));


    if(styleSheet() != style_sheet) {
        setStyleSheet("");
        setStyleSheet(style_sheet);
    }
}

void CardWidget::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);
    QPainter painter(this);

    QFont font("Arial", 30);
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(rect(), Qt::AlignCenter, value);
}
