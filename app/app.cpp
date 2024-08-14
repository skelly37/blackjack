#include "Player.hpp"
#include "Deck.hpp"

#include <fmt/format.h>

#include <iostream>
#include <iomanip>
#include <bits/ranges_algo.h>

void printHeader(const Player &p1, const Player &p2) {
    std::cout << fmt::format("Games (wins/draws/total): | {} ({}) | {} ({})", p1.NAME, p1.getWinsDrawsTotalFormattedString(), p2.NAME, p2.getWinsDrawsTotalFormattedString()) << "\n\n";
}

void printHands(const Player &p1, const Player &p2) {
    std::cout << fmt::format("[{:2}] {:10} {}", p1.getCurrentScore(), p1.NAME + ":", p1.getHand()) << "\n";
    std::cout << fmt::format("[{:2}] {:10} {}", p2.getCurrentScore(), p2.NAME + ":", p2.getHand()) << "\n\n";
}

void print(const Player &p1, const Player &p2) {
    system("clear");
    printHeader(p1, p2);
    printHands(p1, p2);
}

enum class Choice {
    HIT,
    STAND,
};

Choice getUserChoice(const std::string& player_name) {
    char input;
    while (true) {
        std::cout << "Turn of: " << player_name << "\n";
        std::cout << "Press H to hit, S to stand\n";
        std::cin >> input;
        input = tolower(input);

        if (input == 'h') {
            return Choice::HIT;
        }

        if (input == 's') {
            return Choice::STAND;
        }
    }
}

int main() {
    std::array<Player, 2> players{Player{"User"}, Player{"Dealer"}};
    Deck deck;

    std::string input;
    do {
        if(deck.getCardsLeftCount() < 20) {
            deck.reshuffle();
        }

        Player &user = players[0];
        Player &dealer = players[1];

        for(std::size_t i = 0; i<2; ++i) {
            user.addCard(deck.getCard());
            dealer.addCard(deck.getCard());
        }

        print(user, dealer);

        while (std::ranges::any_of(players, [](const Player &player) {
            return player.shouldMove();
        })) {
            for (Player &player: players) {
                print(user, dealer);
                if (player.shouldMove()) {
                    std::ranges::all_of(players, [](const Player &player) {
                        return player.getCurrentScore() <= 21;
                    }) && getUserChoice(player.NAME) == Choice::HIT ? player.addCard(deck.getCard()) : player.stand();
                }
            }
        }

        print(user, dealer);

        if (user.getCurrentScore() == dealer.getCurrentScore()) {
            std::cout << "Draw!\n\n";
            user.draw();
            dealer.draw();
        } else if ((user.getCurrentScore() > dealer.getCurrentScore() && user.getCurrentScore() <= 21) || dealer.getCurrentScore() > 21) {
            std::cout << user.NAME << " wins!\n\n";
            user.win();
            dealer.lose();
        } else {
            std::cout << dealer.NAME <<" wins!\n\n";
            user.lose();
            dealer.win();
        }

        std::cout << "Press Q to quit, any other key to play once again\n";
        std::cout << std::endl;
        std::cin >> input;
    } while (tolower(input[0]) != 'q');
}
