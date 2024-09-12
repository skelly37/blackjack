#include "ui/GameWindow.hpp"
#include "player/Dealer.hpp"
#include "player/User.hpp"

#include <thread>


#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    GameWindow window;
    std::jthread t = window.startGame();
    return app.exec();
}