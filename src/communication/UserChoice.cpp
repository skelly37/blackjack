#include "communication/GameStatus.hpp"
#include "communication/UserChoice.hpp"

#include <thread>

void UserChoice::hit() {
    std::lock_guard l {mtx};
    action = Action::HIT;
}

void UserChoice::stand() {
    std::lock_guard l {mtx};
    action = Action::STAND;
}

UserChoice::Action UserChoice::getChoice() {
    while(GameStatus::getStatus() != GameStatus::Status::STOP_REQUESTED) {
        {
            std::lock_guard l {mtx};
            if(action.has_value()) {
                Action ret = *action;
                action.reset();
                return ret;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    throw AppClosedException{"App closed"};
}
