/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** IComponent
*/

#pragma once

#include <cstddef>

namespace nts{
    enum Tristate {
        T_UNDEFINED = (-true),
        T_TRUE = true,
        T_FALSE = false
    };

    enum ComponentType {
        C_INPUT = 0,
        C_OUTPUT,
        C_CLOCK,
        C_TRUE,
        C_FALSE,

        C_AND,
        C_NAND,
        C_OR,
        C_NOR,
        C_XOR,
        C_NOT,

        C_4081,
        C_4071,
        C_4001,
        C_4030,
        C_4069,
        C_4011
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void reset() = 0;
    };
}
