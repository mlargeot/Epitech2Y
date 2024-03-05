/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Or
*/

#include <iostream>
#include "Or.hpp"

nts::Or::Or(): AChipset(ComponentType::C_OR) {
    this->_pins.addInput(this, 1);
    this->_pins.addInput(this, 2);
    this->_pins.addOutput(this, 3);
}

nts::Or::~Or() {}

nts::Tristate nts::Or::compute(std::size_t pin) {
    if (pin == 3)
        return this->_pins.compute(gate::Or, 1, 2);
    return this->_pins.compute(pin);
}

void nts::Or::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "   Or:" << std::endl;
    std::cout << "}" << std::endl;
}
