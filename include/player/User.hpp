#pragma once

#include "Player.hpp"

class User : public Player {
public:
    explicit User(std::string&& name = "User");

    void move(Deck& deck) override;

private:
    enum class Choice {
        HIT,
        STAND,
    };
    [[nodiscard]] Choice getUserChoice() const;
};