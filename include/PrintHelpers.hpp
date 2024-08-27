#pragma once

#include <fmt/format.h>

#include <iostream>

inline void printHeader(const std::shared_ptr<Player> &p1, const std::shared_ptr<Player> &p2) {
    std::cout << fmt::format("Games (wins/draws/total): | {} ({}) | {} ({})", p1->NAME,
                             p1->getWinsDrawsTotalFormattedString(), p2->NAME,
                             p2->getWinsDrawsTotalFormattedString()) << "\n\n";
}

inline void printHand(const std::shared_ptr<Player> &player) {
    std::cout << fmt::format("[{:2}] {:10} {}", player->getCurrentScore(), player->NAME + ":", player->getHand()) <<
        "\n";
}

inline void printHiddenHand(const std::shared_ptr<Player> &player) {
    Card first_card = player->getFirstCard();

    std::cout << fmt::format("[{:2}] {:10} {}", first_card.value, player->NAME + ":", first_card.to_string());
    for (std::size_t i = 1; i < player->getCardsCount(); ++i) {
        std::cout << " |X|";
    }
    std::cout << "\n";
}

inline void print(const std::shared_ptr<Player> &user, const std::shared_ptr<Player> &dealer, bool hide_dealer = true) {
    system("clear");
    printHeader(user, dealer);
    printHand(user);
    hide_dealer ? printHiddenHand(dealer) : printHand(dealer);
}