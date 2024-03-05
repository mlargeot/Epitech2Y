/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** InputPin
*/

#include <stdexcept>
#include <iostream>
#include "InputPin.hpp"

nts::InputPin::InputPin(nts::AComponent *component, std::size_t pin): nts::APin(component, pin), _value(nts::T_UNDEFINED), _computed(false) {}

void nts::InputPin::setLink(nts::IComponent &other, std::size_t otherPin) {
    if (isSelf(other, otherPin))
        throw std::runtime_error("Pin already linked");
    if (!isLinkedTo(other, otherPin)) {
        if (isLinked())
            throw std::runtime_error("Pin already linked");
        this->_links.emplace_back(other, otherPin);
        other.setLink(otherPin, this->_component, this->_pin);
    }
}

nts::Tristate nts::InputPin::compute() {
    if (!isLinked())
        return nts::T_UNDEFINED;
    if (this->_computed)
        return this->_value;
    this->_computed = true;
    this->_value = this->_links[0].first.get().compute(this->_links[0].second);
    return this->_value;
}

void nts::InputPin::reset() {
    this->_computed = false;
}


//TODO: implement dump
void nts::InputPin::dump() const {
    std::cout << "InputPin: " << this->_pin << std::endl;
}
