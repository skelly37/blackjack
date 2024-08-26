#include "Player.hpp"
#include "Deck.hpp"

#include <fmt/format.h>

#include <iostream>
#include <iomanip>
#include <bits/ranges_algo.h>

void printHeader(const Player &p1, const Player &p2) {
    std::cout << fmt::format("Games (wins/draws/total): | {} ({}) | {} ({})", p1.NAME,
                             p1.getWinsDrawsTotalFormattedString(), p2.NAME,
                             p2.getWinsDrawsTotalFormattedString()) << "\n\n";
}

void printHand(const Player &player) {
    std::cout << fmt::format("[{:2}] {:10} {}", player.getCurrentScore(), player.NAME + ":", player.getHand()) << "\n";
}

void printHiddenHand(const Player &player) {
    Card first_card = player.getFirstCard();

    std::cout << fmt::format("[{:2}] {:10} {}", first_card.value, player.NAME + ":", first_card.to_string());
    for (std::size_t i = 1; i < player.getCardsCount(); ++i) {
        std::cout << " |X|";
    }
    std::cout << "\n";
}

void print(const Player &user, const Player &dealer, bool hide_dealer = true) {
    system("clear");
    printHeader(user, dealer);
    printHand(user);
    hide_dealer ? printHiddenHand(dealer) : printHand(dealer);
}

enum class Choice {
    HIT,
    STAND,
};

Choice getUserChoice(const std::string &player_name) {
    std::string input;
    while (true) {
        std::cout << "Turn of: " << player_name << "\n";
        std::cout << "Press H to hit, S to stand\n";
        std::getline(std::cin, input);

        if (input.empty()) {
            continue;
        }

        char choice = tolower(input[0]);

        if (choice == 'h') {
            return Choice::HIT;
        }

        if (choice == 's') {
            return Choice::STAND;
        }
    }
}

int main() {
    std::array<Player, 2> players{Player{"User"}, Player{"Dealer"}};
    Deck deck;

    std::string input;
    do {
        if (deck.getCardsLeftCount() < 20) {
            deck.reshuffle();
        }

        Player &user = players[0];
        Player &dealer = players[1];

        for (std::size_t i = 0; i < 2; ++i) {
            user.addCard(deck.getCard());
            dealer.addCard(deck.getCard());
        }

        print(user, dealer);

        while (std::ranges::any_of(players, [](const Player &player) {
            return player.shouldMove();
        })) {
            print(user, dealer);
            if (user.shouldMove()) {
                std::ranges::all_of(players, [](const Player &player) {
                    return player.getCurrentScore() <= 21;
                }) && getUserChoice(user.NAME) == Choice::HIT
                    ? user.addCard(deck.getCard())
                    : user.stand();
            }
            print(user, dealer);
            if (dealer.shouldMove()) {
                std::ranges::all_of(players, [](const Player &player) {
                    return player.getCurrentScore() <= 21;
                }) && dealer.getCurrentScore() < 17
                    ? dealer.addCard(deck.getCard())
                    : dealer.stand();
            }
        }

        print(user, dealer, false);

        if (user.getCurrentScore() == dealer.getCurrentScore()) {
            std::cout << "Draw!\n\n";
            user.draw();
            dealer.draw();
        } else if ((user.getCurrentScore() > dealer.getCurrentScore() && user.getCurrentScore() <= 21) || dealer.getCurrentScore() > 21) {
            std::cout << user.NAME << " wins!\n\n";
            user.win();
            dealer.lose();
        } else {
            std::cout << dealer.NAME << " wins!\n\n";
            user.lose();
            dealer.win();
        }

        std::cout << "Press Q to quit, any other key to play once again\n";
        std::cout << std::endl;
        std::getline(std::cin, input);
    } while (tolower(input[0]) != 'q');
}
