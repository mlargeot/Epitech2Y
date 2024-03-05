/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Not
*/

#include <iostream>
#include "Not.hpp"

nts::Not::Not(): AChipset(ComponentType::C_NOT) {
    this->_pins.addInput(this, 1);
    this->_pins.addOutput(this, 2);
}

nts::Tristate nts::Not::compute(std::size_t pin) {
    if (pin == 2)
        return this->_pins.compute(gate::Not, 1, 0);
    return this->_pins.compute(pin);
}

void nts::Not::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "   Not:" << std::endl;
    std::cout << "}" << std::endl;
}

nts::Not::~Not() {}
