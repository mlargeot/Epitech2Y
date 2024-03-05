/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Clock
*/

#pragma once

#include "Components/IO/Input.hpp"

namespace nts {
    class Clock : public Input {
        public:
            explicit Clock(Tristate value);
            void reverseValue();
            Tristate compute(std::size_t pin) override;
            void dump() const override;
    };
}