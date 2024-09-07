#include "ui/CardWidget.hpp"

#include <QPainter>
#include <fmt/format.h>

CardWidget::CardWidget(QString value, QWidget *parent) : QFrame(parent), value(value) {
    setFrameStyle(Panel | Sunken);
    setLineWidth(2);
    setFixedSize(77, 92);
    setBackground(CardAssets::EMPTY);
}

void CardWidget::setBackground(const std::filesystem::path &image) {
    const std::string image_path = ASSETS_DIR / image;
    const std::string style_sheet = fmt::format("QFrame {{ background-image: url({}); color: orange; border: 1px solid black; }}", image_path);
    setStyleSheet(style_sheet.c_str());
}

void CardWidget::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);
    QPainter painter(this);

    QFont font("Arial", 30);
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(rect(), Qt::AlignCenter, value);
}