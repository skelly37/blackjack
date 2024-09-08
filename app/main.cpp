#include "ui/GameWindow.hpp"
#include "player/Dealer.hpp"
#include "player/User.hpp"

#include <thread>


#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    GameWindow window {std::make_shared<User>(), std::make_shared<Dealer>()};
    std::jthread t{[&] {
                       window.gameLoop();
                   }};

    return app.exec();
}