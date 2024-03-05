/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** C4030
*/

#pragma once

#include "AChipset.hpp"

namespace nts {
    class C4030 : public AChipset {
        public:
            C4030();
            void dump() const override;
            Tristate compute(std::size_t pin) override;
    };
}