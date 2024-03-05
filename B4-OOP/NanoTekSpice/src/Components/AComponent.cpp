/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** AComponent
*/

#include "AComponent.hpp"

nts::ComponentType nts::AComponent::getType() const {
    return this->_type;
}

nts::AComponent::AComponent(nts::ComponentType type): _type(type) {}
