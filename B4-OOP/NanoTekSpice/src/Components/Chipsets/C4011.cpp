/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** C4011
*/

#include <iostream>
#include "C4011.hpp"

nts::C4011::C4011(): AChipset(ComponentType::C_4011) {
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

void nts::C4011::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "type: C4011" << std::endl;
   // std::cout << "value: " << this << std::endl;
    std::cout << "}" << std::endl;
}

nts::Tristate nts::C4011::compute(std::size_t pin) {
    switch (pin) {
        case 3:
            return _pins.compute(gate::Nand, 1, 2);
        case 4:
            return _pins.compute(gate::Nand, 5, 6);
        case 10:
            return _pins.compute(gate::Nand, 8, 9);
        case 11:
            return _pins.compute(gate::Nand, 12, 13);
        default:
            return _pins.compute(pin);
    }
}
