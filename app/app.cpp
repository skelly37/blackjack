#include "game/UserDealerGame.hpp"

#include <iostream>


// todo odcouplowac output od logiki
// todo wiecej testow
// todo przekminic qt czy cos tego typu

int main() {
    std::string input;
    std::unique_ptr<Game> game = std::make_unique<UserDealerGame>();
    do {
        game->play();
        std::getline(std::cin, input);
    } while (tolower(input[0]) != 'q');
}
