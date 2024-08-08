#pragma once

#include "io/IO.hpp"

class StubIO : public IO {
public:
    explicit StubIO(std::function<UserChoice()> choice_getter = []{return UserChoice::STAND;}) : choice_getter(std::move(choice_getter)) {
    }

    void displayDraw(const std::shared_ptr<Player>& p1, const std::shared_ptr<Player>& p2) override {
    }
    void displayWin(const std::shared_ptr<Player>& winner) override {
    }

    [[nodiscard]] UserChoice getUserChoice(std::string_view name) override {
        return choice_getter();
    }

protected:
    void displayGameUI(const std::shared_ptr<Player>& user, const std::shared_ptr<Player>& dealer, bool is_dealer_visible) override {
    }

private:
    std::function<UserChoice()> choice_getter;
};