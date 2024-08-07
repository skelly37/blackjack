#include "Card.hpp"
#include <fmt/format.h>

#include <iostream>

int main() {
    std::cout << fmt::format("test lib: {}", Card(Card::Symbol::ACE, Card::Color::CLUBS).to_string());
}