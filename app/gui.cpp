#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QPainter>
#include <fmt/format.h>

#include <filesystem>

class CardWidget : public QFrame {
public:
    explicit CardWidget(QString value, QWidget *parent = nullptr) : QFrame(parent), cardValue(std::move(value)) {
        setFrameStyle(QFrame::Panel | QFrame::Sunken);
        setLineWidth(2);
        setFixedSize(77, 92);

        // fixme smarter background image
        const std::string image_path = ASSETS_DIR / std::filesystem::path{"back.png"};
        const std::string asset_path = fmt::format("QFrame {{ background-image: url({}); color: orange; border: 1px solid black; }}", image_path);
        setStyleSheet(asset_path.c_str());
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QFrame::paintEvent(event);
        QPainter painter(this);

        QFont font("Arial", 30);
        font.setBold(true);
        painter.setFont(font);
        painter.drawText(rect(), Qt::AlignCenter, cardValue);
    }

private:
    QString cardValue;
};

class BlackjackGUI : public QWidget {
public:
    explicit BlackjackGUI(QWidget *parent = nullptr) : QWidget(parent) {
        // fixme make it actually aligned to the cards
        auto *player_name = new QLabel("player_name (W: 2 | D: 1 | T: 3)");
        player_name->setAlignment(Qt::AlignCenter);
        player_name->setStyleSheet("QLabel { color : black; font-size: 16px; }");

        auto *dealer_name = new QLabel("Dealer (W: 0 | D: 1 | T: 3)");
        dealer_name->setAlignment(Qt::AlignCenter);
        dealer_name->setStyleSheet("QLabel { color: black; font-size: 16px; }");

        auto *player_card1 = new CardWidget("2");
        auto *player_card2 = new CardWidget("3");
        auto *player_card3 = new CardWidget("A");
        auto *player_card4 = new CardWidget("K");
        auto *player_card5 = new CardWidget("5");
        auto *player_card6 = new CardWidget("3");
        auto *player_card7 = new CardWidget("1");
        auto *player_card8 = new CardWidget("K");
        auto *player_card9 = new CardWidget("J");
        auto *player_card10 = new CardWidget("10");
        auto *player_total = new QLabel("10");
        player_total->setStyleSheet("QLabel {color: black; font-size: 20px; font-weight: bold}");

        auto *player_grid = new QGridLayout;
        player_grid->addWidget(player_card1, 0, 0);
        player_grid->addWidget(player_card2, 0, 1);
        player_grid->addWidget(player_card3, 0, 2);
        player_grid->addWidget(player_card4, 0, 3);
        player_grid->addWidget(player_card5, 0, 4);
        player_grid->addWidget(player_card6, 1, 0);
        player_grid->addWidget(player_card7, 1, 1);
        player_grid->addWidget(player_card8, 1, 2);
        player_grid->addWidget(player_card9, 1, 3);
        player_grid->addWidget(player_card10, 1, 4);
        player_grid->addWidget(player_total, 2, 0, 1, 5, Qt::AlignCenter);

        auto *dealer_card1 = new CardWidget("2");
        auto *dealer_card2 = new CardWidget("");
        auto *dealer_card3 = new CardWidget("");
        auto *dealer_card4 = new CardWidget("");
        auto *dealer_card5 = new CardWidget("");
        auto *dealer_card6 = new CardWidget("");
        auto *dealer_card7 = new CardWidget("");
        auto *dealer_card8 = new CardWidget("");
        auto *dealer_card9 = new CardWidget("");
        auto *dealer_card10 = new CardWidget("");

        auto *dealer_total = new QLabel("2");
        dealer_total->setStyleSheet("QLabel {color: black; font-size: 20px; font-weight: bold}");

        auto *dealer_grid = new QGridLayout;
        dealer_grid->addWidget(dealer_card1, 0, 0);
        dealer_grid->addWidget(dealer_card2, 0, 1);
        dealer_grid->addWidget(dealer_card3, 0, 2);
        dealer_grid->addWidget(dealer_card4, 0, 3);
        dealer_grid->addWidget(dealer_card5, 0, 4);
        dealer_grid->addWidget(dealer_card6, 1, 0);
        dealer_grid->addWidget(dealer_card7, 1, 1);
        dealer_grid->addWidget(dealer_card8, 1, 2);
        dealer_grid->addWidget(dealer_card9, 1, 3);
        dealer_grid->addWidget(dealer_card10, 1, 4);
        dealer_grid->addWidget(dealer_total, 2, 0, 1, 5, Qt::AlignCenter);

        auto *cards_layout = new QHBoxLayout;
        cards_layout->addStretch();
        cards_layout->addLayout(player_grid);
        cards_layout->addStretch();
        cards_layout->addLayout(dealer_grid);
        cards_layout->addStretch();

        auto *centered_cards_layout = new QVBoxLayout;
        centered_cards_layout->addStretch();
        centered_cards_layout->addLayout(cards_layout);
        centered_cards_layout->addStretch();

        auto *stats_layout = new QGridLayout;
        stats_layout->addWidget(player_name, 0, 1, Qt::AlignCenter);
        stats_layout->addWidget(dealer_name, 0, 3, Qt::AlignCenter);

        stats_layout->setColumnStretch(0, 1);
        stats_layout->setColumnStretch(2, 1);
        stats_layout->setColumnStretch(4, 1);

        auto *top_layout = new QVBoxLayout;
        top_layout->addLayout(stats_layout);
        top_layout->addSpacing(20);

        auto *hit_button = new QPushButton("Hit");
        auto *stand_button = new QPushButton("Stand");
        hit_button->setStyleSheet(
            "QPushButton {color: black; font-size: 20px; font-weight: bold; background-color: lightgray}"
            "QPushButton:hover {color: black; font-size: 20px; font-weight: bold; background-color: gray}"
            );
        stand_button->setStyleSheet(
            "QPushButton {color: black; font-size: 20px; font-weight: bold; background-color: lightgray}"
            "QPushButton:hover {color: black; font-size: 20px; font-weight: bold; background-color: gray}"
            );

        auto *buttons_layout = new QHBoxLayout;
        buttons_layout->addWidget(hit_button);
        buttons_layout->addWidget(stand_button);

        auto *main_layout = new QVBoxLayout;
        main_layout->addLayout(top_layout);
        main_layout->addLayout(centered_cards_layout);
        main_layout->addLayout(buttons_layout);

        setLayout(main_layout);

        setStyleSheet("QWidget { background-color: beige; }");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    BlackjackGUI window;
    window.setWindowTitle("Blackjack");
    window.resize(900, 600);
    window.show();

    return app.exec();
}