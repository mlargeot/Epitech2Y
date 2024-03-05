/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Chipset
*/

#include "AChipset.hpp"

nts::AChipset::AChipset(nts::ComponentType type) : AComponent(type) {}

void nts::AChipset::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    this->_pins.setLink(pin, other, otherPin);
}

void nts::AChipset::reset() {
    this->_pins.reset();
}
