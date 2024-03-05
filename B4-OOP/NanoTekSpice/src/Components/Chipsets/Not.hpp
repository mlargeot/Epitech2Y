/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Not
*/

#pragma once

#include "AChipset.hpp"

namespace nts {
    class Not : public AChipset {
    public:
        Not();
        ~Not();
        Tristate compute(std::size_t pin) override;
        void dump() const override;
    };
}