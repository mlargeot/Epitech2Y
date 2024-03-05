/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** C4069
*/

#include <iostream>
#include "C4069.hpp"

nts::C4069::C4069(): AChipset(ComponentType::C_4069) {
    this->_pins.addInput(this, 1);
    this->_pins.addOutput(this, 2);

    this->_pins.addInput(this, 3);
    this->_pins.addOutput(this, 4);

    this->_pins.addInput(this, 5);
    this->_pins.addOutput(this, 6);

    this->_pins.addOutput(this, 8);
    this->_pins.addInput(this, 9);

    this->_pins.addOutput(this, 10);
    this->_pins.addInput(this, 11);

    this->_pins.addOutput(this, 12);
    this->_pins.addInput(this, 13);

    this->_pins.addOutput(this, 7);
    this->_pins.addInput(this, 14);
}

void nts::C4069::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "type: C4069" << std::endl;
//    std::cout << "value: " << this << std::endl;
    std::cout << "}" << std::endl;
}

nts::Tristate nts::C4069::compute(std::size_t pin) {
    switch (pin) {
        case 2:
            return this->_pins.compute(gate::Not, 1, 0);
        case 4:
            return this->_pins.compute(gate::Not, 3, 0);
        case 6:
            return this->_pins.compute(gate::Not, 5, 0);
        case 8:
            return this->_pins.compute(gate::Not, 9, 0);
        case 10:
            return this->_pins.compute(gate::Not, 11, 0);
        case 12:
            return this->_pins.compute(gate::Not, 13, 0);
        default:
            return this->_pins.compute(pin);
    }
}
