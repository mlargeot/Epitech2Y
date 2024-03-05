/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** False
*/

#pragma once

#include "Components/IO/Input.hpp"

namespace nts {
    class False : public Input {
        public:
            False();
            void setNextValue(Tristate value) override;
            void dump() const override;
    };
}