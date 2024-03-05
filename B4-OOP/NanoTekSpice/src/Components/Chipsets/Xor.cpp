/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Xor
*/

#include <iostream>
#include "Xor.hpp"

nts::Xor::Xor(): AChipset(ComponentType::C_XOR) {
    this->_pins.addInput(this, 1);
    this->_pins.addInput(this, 2);
    this->_pins.addOutput(this, 3);
}

nts::Xor::~Xor() {}

nts::Tristate nts::Xor::compute(std::size_t pin) {
    if (pin == 3)
        return this->_pins.compute(gate::Xor, 1, 2);
    return this->_pins.compute(pin);
}

void nts::Xor::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "   Xor:" << std::endl;
    std::cout << "}" << std::endl;
}
