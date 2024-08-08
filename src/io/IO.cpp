#include "io/IO.hpp"

void IO::displayGameUIWithP2Hidden(const std::shared_ptr<Player> &p1, const std::shared_ptr<Player> &p2) {
    displayGameUI(p1, p2, true);
}

void IO::displayGameUIWithP2Visible(const std::shared_ptr<Player> &p1, const std::shared_ptr<Player> &p2) {
    displayGameUI(p1, p2, false);
}
