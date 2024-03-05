/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Output
*/

#include <iostream>
#include "Output.hpp"

nts::Output::Output(): AComponent(ComponentType::C_OUTPUT), _value(Tristate::T_UNDEFINED), _pin(this, 1) {}

void nts::Output::reset() {
    this->_value = Tristate::T_UNDEFINED;
    this->_pin.reset();
}

nts::Tristate nts::Output::compute(std::size_t) {
    if (!this->_pin.isLinked())
        throw std::runtime_error("Pin not linked");
    this->_value = this->_pin.compute();
    return this->_value;
}

void nts::Output::setValue(nts::Tristate value) {
    this->_value = value;
}

void nts::Output::setLink(std::size_t, nts::IComponent &other, std::size_t otherPin) {
    this->_pin.setLink(other, otherPin);
}

nts::Tristate nts::Output::getValue() const {
    return this->_value;
}

void nts::Output::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "type: Output" << std::endl;
    std::cout << "Value: " << this->_value << std::endl;
    std::cout << "}" << std::endl;
}
