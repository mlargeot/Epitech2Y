/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** PinMap
*/

#include <stdexcept>
#include "PinMap.hpp"
#include "InputPin.hpp"
#include "OutputPin.hpp"

void nts::PinMap::addInput(nts::AComponent *component, std::size_t pin) {
    this->_pins[pin] = std::make_unique<InputPin>(component, pin);
}

void nts::PinMap::addOutput(nts::AComponent *component, std::size_t pin) {
    this->_pins[pin] = std::make_unique<OutputPin>(component, pin);
}

bool nts::PinMap::isValid(std::size_t pin) const {
    return (this->_pins.find(pin) != this->_pins.end());
}

bool nts::PinMap::isLinked(std::size_t pin) const {
    return this->_pins.find(pin)->second->isLinked();
}

nts::Tristate nts::PinMap::compute(std::size_t pin) {
    return this->_pins[pin]->compute();
}

nts::Tristate nts::PinMap::compute(const nts::PinMap::GateFunc &gate, std::size_t pinA, std::size_t pinB) {
    if (pinB == 0) {
        if (!this->isValid(pinA))
            throw std::out_of_range("Pin not found");
        return gate(this->compute(pinA), Tristate::T_UNDEFINED);
    }
    if (!this->isValid(pinA) || !this->isValid(pinB))
        throw std::out_of_range("Pin not found");
    return gate(this->compute(pinA), this->compute(pinB));
}

void nts::PinMap::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    this->_pins[pin]->setLink(other, otherPin);
}

void nts::PinMap::reset() {
    for (auto &pin : this->_pins) {
        pin.second->reset();
    }
}

void nts::PinMap::dump() const {
    for (auto &pin : this->_pins) {
        pin.second->dump();
    }
}
