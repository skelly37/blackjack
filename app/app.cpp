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
    std::cout << fmt::format("[{:2}] {}: {}", p1.getCurrentScore(), p1.NAME, p1.getHand()) << "\n";
    std::cout << fmt::format("[{:2}] {}: {}", p2.getCurrentScore(), p2.NAME, p2.getHand()) << "\n\n";
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
    std::array<Player, 2> players{Player{"player1"}, Player{"player2"}};
    Deck deck;

    std::string input;
    do {
        if(deck.getCardsLeftCount() < 20) {
            deck.reshuffle();
        }

        Player &p0 = players[0];
        Player &p1 = players[1];

        while (std::ranges::any_of(players, [](const Player &player) {
            return player.shouldMove();
        })) {
            for (Player &player: players) {
                print(p0, p1);
                if (player.shouldMove()) {
                    std::ranges::all_of(players, [](const Player &player) {
                        return player.getCurrentScore() <= 21;
                    }) && getUserChoice(player.NAME) == Choice::HIT ? player.addCard(deck.getCard()) : player.stand();
                }
            }
        }

        print(p0, p1);

        if (p0.getCurrentScore() == p1.getCurrentScore()) {
            std::cout << "Draw!\n\n";
            p0.draw();
            p1.draw();
        } else if ((p0.getCurrentScore() > p1.getCurrentScore() && p0.getCurrentScore() <= 21) || p1.getCurrentScore() > 21) {
            std::cout << "Player 1 wins!\n\n";
            p0.win();
            p1.lose();
        } else {
            std::cout << "Player 2 wins!\n\n";
            p0.lose();
            p1.win();
        }

        std::cout << "Press Q to quit, any other key to play once again\n";
        std::cout << std::endl;
        std::cin >> input;
    } while (tolower(input[0]) != 'q');
}
