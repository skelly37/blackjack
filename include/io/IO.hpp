#pragma once

#include "player/Player.hpp"

#include <memory>

class IO {
public:
    virtual ~IO() = default;

    void displayGameUIWithP2Hidden(const std::shared_ptr<Player>& p1, const std::shared_ptr<Player>& p2);
    void displayGameUIWithP2Visible(const std::shared_ptr<Player>& p1, const std::shared_ptr<Player>& p2);

    virtual void displayDraw(const std::shared_ptr<Player>& p1, const std::shared_ptr<Player>& p2) = 0;
    virtual void displayWin(const std::shared_ptr<Player>& winner) = 0;

    enum class UserChoice {
        HIT,
        STAND,
    };
    [[nodiscard]] virtual UserChoice getUserChoice(std::string_view name) = 0;

protected:
    virtual void displayGameUI(const std::shared_ptr<Player>& user, const std::shared_ptr<Player>& dealer, bool is_dealer_visible) = 0;
};
