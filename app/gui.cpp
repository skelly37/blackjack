#include "ui/GameWindow.hpp"
#include "player/Dealer.hpp"
#include "player/User.hpp"

#include "../test/utils/StubIO.hpp"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    GameWindow window {std::make_shared<User>(std::make_shared<StubIO>()), std::make_shared<Dealer>()};

    return app.exec();
}