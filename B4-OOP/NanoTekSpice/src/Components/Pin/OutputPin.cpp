/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** OutputPin
*/

#include "OutputPin.hpp"
#include <stdexcept>
#include <iostream>

nts::OutputPin::OutputPin(nts::AComponent *component, std::size_t pin) : APin(component, pin) {}

void nts::OutputPin::setLink(nts::IComponent &other, std::size_t otherPin) {
    if (isSelf(other, otherPin))
        throw std::runtime_error("Cannot link a pin to itself");
    if(!isLinkedTo(other, otherPin)) {
        if (isLinked())
            throw std::runtime_error("Pin already linked");
        this->_links.emplace_back(other, otherPin);
        other.setLink(otherPin, this->_component, this->_pin);
    }
}

nts::Tristate nts::OutputPin::compute() {
    return nts::T_UNDEFINED;
}

void nts::OutputPin::reset() {}

//TODO: implement dump
void nts::OutputPin::dump() const {
    std::cout << "OutputPin: " << this->_pin << std::endl;
}
