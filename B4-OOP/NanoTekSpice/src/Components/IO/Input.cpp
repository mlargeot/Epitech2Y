/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Input
*/

#include <stdexcept>
#include <iostream>
#include "Input.hpp"

nts::Input::Input(ComponentType type, Tristate value): AComponent(type), _value(Tristate::T_UNDEFINED), _nextValue(value), _pin(this, 1) {}

nts::Tristate nts::Input::compute(std::size_t pin) {
    if (pin == 1)
        return this->_value;
    throw std::out_of_range("Pin out of range");
}

nts::Tristate nts::Input::getValue() const {
    return this->_value;
}

void nts::Input::setValue(nts::Tristate value) {
    this->_value = value;
}

void nts::Input::reset() {
    this->_pin.reset();
}

void nts::Input::setLink(std::size_t, nts::IComponent &other, std::size_t otherPin) {
    this->_pin.setLink(other, otherPin);
}

void nts::Input::setNextValue(nts::Tristate value) {
    this->_nextValue = value;
}

void nts::Input::updateState() {
    this->_value = this->_nextValue;
}

void nts::Input::dump() const {
    std::cout << "{" << std::endl;
    std::cout << "type: Input" << std::endl;
    std::cout << "Value: " << this->_value << std::endl;
    std::cout << "}" << std::endl;
}
