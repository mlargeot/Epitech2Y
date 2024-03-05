/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** True
*/

#include <iostream>
#include "True.hpp"

nts::True::True(): Input(nts::ComponentType::C_TRUE, Tristate::T_TRUE) {
    this->_nextValue = Tristate::T_TRUE;
    this->_value = Tristate::T_TRUE;
}

void nts::True::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "type: True" << std::endl;
    std::cout << "Value: True" << std::endl;
    std::cout << "}" << std::endl;
}

void nts::True::setNextValue(nts::Tristate) {}
