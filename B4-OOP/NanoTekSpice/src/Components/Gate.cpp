/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Gate
*/

#include "Gate.hpp"

nts::Tristate gate::And(nts::Tristate a, nts::Tristate b) {
    if (a == nts::T_FALSE || b == nts::T_FALSE)
        return nts::T_FALSE;
    if (a == nts::T_UNDEFINED || b == nts::T_UNDEFINED)
        return nts::T_UNDEFINED;
    return nts::T_TRUE;
}

nts::Tristate gate::Nand(nts::Tristate a, nts::Tristate b) {
    return Not(And(a, b), nts::T_UNDEFINED);
}

nts::Tristate gate::Not(nts::Tristate a, nts::Tristate) {
    if (a == nts::T_TRUE)
        return nts::T_FALSE;
    if (a == nts::T_FALSE)
        return nts::T_TRUE;
    return nts::T_UNDEFINED;
}

nts::Tristate gate::Or(nts::Tristate a, nts::Tristate b) {
    if (a == nts::T_TRUE || b == nts::T_TRUE)
        return nts::T_TRUE;
    if (a == nts::T_UNDEFINED || b == nts::T_UNDEFINED)
        return nts::T_UNDEFINED;
    return nts::T_FALSE;
}

nts::Tristate gate::Nor(nts::Tristate a, nts::Tristate b) {
    return Not(Or(a, b), nts::T_UNDEFINED);
}

nts::Tristate gate::Xor(nts::Tristate a, nts::Tristate b) {
    if (a == nts::T_UNDEFINED || b == nts::T_UNDEFINED)
        return nts::T_UNDEFINED;
    if (a != b)
        return nts::T_TRUE;
    return nts::T_FALSE;
}
