/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Gate
*/

#pragma once

#include "IComponent.hpp"

namespace gate {
    nts::Tristate And(nts::Tristate a, nts::Tristate b);
    nts::Tristate Nand(nts::Tristate a, nts::Tristate b);
    nts::Tristate Not(nts::Tristate a, nts::Tristate b);
    nts::Tristate Or(nts::Tristate a, nts::Tristate b);
    nts::Tristate Nor(nts::Tristate a, nts::Tristate b);
    nts::Tristate Xor(nts::Tristate a, nts::Tristate b);
}
