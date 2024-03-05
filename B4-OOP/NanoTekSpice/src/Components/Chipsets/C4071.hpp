/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** C4071
*/

#pragma once

#include "AChipset.hpp"

namespace nts {
    class C4071 : public AChipset {
        public:
            C4071();
            void dump() const override;
            Tristate compute(std::size_t pin) override;
    };
}