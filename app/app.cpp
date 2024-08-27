#include "game/UserDealerGame.hpp"
#include "io/TerminalIO.hpp"

#include <iostream>

// todo wiecej testow
// todo przekminic qt czy cos tego typu

int main() {
    std::string input;
    std::shared_ptr<TerminalIO> io = std::make_shared<TerminalIO>();
    std::unique_ptr<Game> game = std::make_unique<UserDealerGame>(io);
    do {
        game->play();
        std::getline(std::cin, input);
    } while (tolower(input[0]) != 'q');
}
