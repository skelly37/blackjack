#pragma once

#include "io/IO.hpp"

class TerminalIO : public IO {
public:
    [[nodiscard]] UserChoice getUserChoice(std::string_view name) override;

    void displayDraw(const std::shared_ptr<Player>& p1, const std::shared_ptr<Player>& p2) override;
    void displayWin(const std::shared_ptr<Player>& winner) override;

private:
    void displayGameUI(const std::shared_ptr<Player>& user, const std::shared_ptr<Player>& dealer, bool is_dealer_visible) override;

    static void displayPlayer(const std::shared_ptr<Player>& player);
    static void displayPlayerWithHiddenHand(const std::shared_ptr<Player>& player);
    static void displayHeader(const std::shared_ptr<Player>& p1, const std::shared_ptr<Player>& p2);
    static void displayFinalMessage();

    [[nodiscard]] static std::string formatHand(const std::shared_ptr<Player>& player);
    [[nodiscard]] static std::string formatWinsDrawsTotalGames(const std::shared_ptr<Player>& player);
};