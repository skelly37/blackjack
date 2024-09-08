#include "communication/GameStatus.hpp"
#include "communication/UserChoice.hpp"

#include <thread>

void UserChoice::hit() {
    std::lock_guard l {write_mtx};
    action = Action::HIT;
}

void UserChoice::stand() {
    std::lock_guard l {write_mtx};
    action = Action::STAND;
}

UserChoice::Action UserChoice::getChoice() {
    while(true) {
        if (GameStatus::getStatus() == GameStatus::Status::STOP_REQUESTED) {
            throw AppClosedException{"App closed"};
        }

        {
            std::lock_guard l {read_mtx};
            if(action.has_value()) {
                std::lock_guard l2 {write_mtx};
                if(action.has_value()) {
                    Action ret = *action;
                    action.reset();
                    return ret;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
