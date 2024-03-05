/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Pin
*/

#include "APin.hpp"

nts::APin::APin(nts::AComponent *component, std::size_t pin): _component(*component), _pin(pin) {}

bool nts::APin::isLinked() const {
    return !this->_links.empty();
}

bool nts::APin::isSelf(IComponent &component, std::size_t pin) const {
    return (&this->_component == &component && _pin == pin);
}

bool nts::APin::isLinkedTo(nts::IComponent &component, std::size_t pin) const {
    for (auto &link : this->_links) {
        if (&link.first.get() == &component && link.second == pin)
            return true;
    }
    return false;
}
