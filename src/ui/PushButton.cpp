#include "ui/PushButton.hpp"

PushButton::PushButton(std::unique_ptr<PushButtonState> initial_state, QWidget *parent) : QPushButton(parent) {
    setState(std::move(initial_state));
    setStyleSheet("");
    setStyleSheet(
        "QPushButton {color: black; font-size: 20px; font-weight: bold; background-color: lightgray}"
        "QPushButton:hover {color: black; font-size: 20px; font-weight: bold; background-color: gray}"
        );
}

void PushButton::setNextState() {
    setState(state->nextState());
}

void PushButton::setState(std::unique_ptr<PushButtonState> state) {
    this->state = std::move(state);

    setText(this->state->text());
    this->callback = this->state->callback();

    connect(this, &QPushButton::released, this, &PushButton::executeCallback);
}

void PushButton::executeCallback() {
    callback();
}
