/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** CLock
*/

#include <stdexcept>
#include <iostream>
#include "Clock.hpp"

nts::Clock::Clock(nts::Tristate value): Input(nts::ComponentType::C_CLOCK, value) {
    this->_nextValue = value;
}

nts::Tristate nts::Clock::compute(std::size_t pin) {
    if (pin != 1)
        throw std::out_of_range("Pin index out of range");
    return this->_value;
}

void nts::Clock::reverseValue() {
    if (this->_value == nts::T_UNDEFINED && this->_nextValue == nts::T_UNDEFINED)
        return;
    this->_nextValue = (this->_value == nts::T_TRUE) ? nts::T_FALSE : nts::T_TRUE;
}

void nts::Clock::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "type: Clock" << std::endl;
    std::cout << "Value: " << this->_value << std::endl;
    std::cout << "}" << std::endl;
}
