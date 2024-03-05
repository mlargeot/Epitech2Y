/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** False
*/

#include <iostream>
#include "False.hpp"

nts::False::False(): Input(ComponentType::C_FALSE, Tristate::T_FALSE) {
    this->_nextValue = Tristate::T_FALSE;
    this->_value = Tristate::T_FALSE;
}

void nts::False::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "type: False" << std::endl;
    std::cout << "Value: False" << std::endl;
    std::cout << "}" << std::endl;
}

void nts::False::setNextValue(nts::Tristate) {}
