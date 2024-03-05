/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** And
*/

#include "And.hpp"
#include <Components/Pin/InputPin.hpp>
#include <iostream>

nts::And::And(): AChipset(ComponentType::C_AND) {
    _pins.addInput(this, 1);
    _pins.addInput(this, 2);

    _pins.addOutput(this, 3);
}

nts::And::~And() {}

nts::Tristate nts::And::compute(std::size_t pin) {
    if (pin == 3)
        return this->_pins.compute(gate::And, 1, 2);
    return this->_pins.compute(pin);
}

void nts::And::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "   And:" << std::endl;
    std::cout << "}" << std::endl;
}
