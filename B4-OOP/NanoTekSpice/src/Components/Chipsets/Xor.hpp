/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Xor
*/

#pragma once

#include "AChipset.hpp"

namespace nts {
    class Xor : public AChipset {
        public:
            Xor();
            ~Xor();

            Tristate compute(std::size_t pin) override;
            void dump() const override;
    };
}