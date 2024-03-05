/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** C4071
*/

#include <iostream>
#include "C4071.hpp"

nts::C4071::C4071(): AChipset(ComponentType::C_4071) {
    this->_pins.addInput(this, 1);
    this->_pins.addInput(this, 2);
    this->_pins.addOutput(this, 3);

    this->_pins.addInput(this, 5);
    this->_pins.addInput(this, 6);
    this->_pins.addOutput(this, 4);

    this->_pins.addOutput(this, 10);
    this->_pins.addInput(this, 9);
    this->_pins.addInput(this, 8);

    this->_pins.addOutput(this, 11);
    this->_pins.addInput(this, 13);
    this->_pins.addInput(this, 12);

    this->_pins.addOutput(this, 7);
    this->_pins.addInput(this, 14);
}

void nts::C4071::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "type: C4071" << std::endl;
    std::cout << "}" << std::endl;
}

nts::Tristate nts::C4071::compute(std::size_t pin) {
    switch (pin) {
        case 3:
            return _pins.compute(gate::Or, 1, 2);
        case 4:
            return _pins.compute(gate::Or, 5, 6);
        case 10:
            return _pins.compute(gate::Or, 8, 9);
        case 11:
            return _pins.compute(gate::Or, 12, 13);
        default:
            return _pins.compute(pin);
    }
}
