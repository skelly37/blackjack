#include "io/TerminalIO.hpp"

#include <boost/algorithm/string/trim.hpp>
#include <fmt/format.h>

#include <iostream>
#include <numeric>

IO::UserChoice TerminalIO::getUserChoice(std::string_view name) {
    std::string input;
    while (true) {
        std::cout << "Turn of: " << name << "\n";
        std::cout << "Press H to hit, S to stand\n";
        std::getline(std::cin, input);

        if (input.empty()) {
            continue;
        }

        switch (tolower(input[0])) {
        case 'h':
            return UserChoice::HIT;
        case 's':
            return UserChoice::STAND;
        default:
            break;
        }
    }
}

void TerminalIO::displayDraw(const std::shared_ptr<Player> &p1, const std::shared_ptr<Player> &p2) {
    std::cout << "Draw!\n\n";
    displayFinalMessage();
}

void TerminalIO::displayWin(const std::shared_ptr<Player> &winner) {
    std::cout << winner->NAME << " wins!\n\n";
    displayFinalMessage();
}

void TerminalIO::displayGameUI(const std::shared_ptr<Player> &user, const std::shared_ptr<Player> &dealer,
                               bool is_dealer_visible) {
    system("clear");
    displayHeader(user, dealer);
    displayPlayer(user);
    is_dealer_visible ? displayPlayerWithHiddenHand(dealer) : displayPlayer(dealer);
}

void TerminalIO::displayPlayer(const std::shared_ptr<Player> &player) {
    std::cout
        << fmt::format("[{:2}] {:10} {}", player->getCurrentScore(), player->NAME + ":", formatHand(player))
        << "\n";
}

void TerminalIO::displayPlayerWithHiddenHand(const std::shared_ptr<Player> &player) {
    Card first_card = player->getFirstCard();

    std::cout << fmt::format("[{:2}] {:10} {}", first_card.value, player->NAME + ":", first_card.to_string());
    for (std::size_t i = 1; i < player->getCardsCount(); ++i) {
        std::cout << " |X|";
    }
    std::cout << "\n";
}

void TerminalIO::displayHeader(const std::shared_ptr<Player> &p1, const std::shared_ptr<Player> &p2) {
    std::cout
        << fmt::format("Games (wins/draws/total): | {} ({}) | {} ({})",
                       p1->NAME, formatWinsDrawsTotalGames(p1),
                       p2->NAME, formatWinsDrawsTotalGames(p2))
        << "\n\n";
}

void TerminalIO::displayFinalMessage() {
    std::cout << "Press Q to quit, any other key to play once again\n\n";
}

[[nodiscard]] std::string TerminalIO::formatHand(const std::shared_ptr<Player> &player) {
    const std::vector<Card> &hand = player->getHand();
    std::string result = std::accumulate(hand.begin(), hand.end(), std::string{""},
                                         [](const std::string &acc, const Card &card) {
        return acc + card.to_string() + " ";
    });

    boost::algorithm::trim(result);
    return result;
}

std::string TerminalIO::formatWinsDrawsTotalGames(const std::shared_ptr<Player> &player) {
    return fmt::format("{}/{}/{}", player->getWins(), player->getDraws(), player->getPlayedGames());
}
