/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** And
*/

#pragma once

#include "AChipset.hpp"

namespace nts {
    class And : public AChipset {
        public:
            And();
            ~And() override;
            Tristate compute(std::size_t pin) override;
            void dump() const override;
    };
}