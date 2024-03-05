/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** C4001
*/

#include <iostream>
#include "C4001.hpp"

nts::C4001::C4001(): AChipset(ComponentType::C_4001) {
    this->_pins.addInput(this, 1);
    this->_pins.addInput(this, 2);
    this->_pins.addOutput(this, 3);

    this->_pins.addOutput(this, 4);
    this->_pins.addInput(this, 5);
    this->_pins.addInput(this, 6);

    this->_pins.addInput(this, 8);
    this->_pins.addInput(this, 9);
    this->_pins.addOutput(this, 10);

    this->_pins.addOutput(this, 11);
    this->_pins.addInput(this, 12);
    this->_pins.addInput(this, 13);

    this->_pins.addOutput(this, 7);
    this->_pins.addInput(this, 14);
}

void nts::C4001::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "type: C4001" << std::endl;
//    std::cout << "value: " << this << std::endl;
    std::cout << "}" << std::endl;
}

nts::Tristate nts::C4001::compute(std::size_t pin) {
    switch (pin) {
        case 3:
            return _pins.compute(gate::Nor, 1, 2);
        case 4:
            return _pins.compute(gate::Nor, 5, 6);
        case 10:
            return _pins.compute(gate::Nor, 8, 9);
        case 11:
            return _pins.compute(gate::Nor, 12, 13);
        default:
            return _pins.compute(pin);
    }
}
