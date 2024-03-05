/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Output
*/

#pragma once

#include "APin.hpp"

namespace nts {
    class OutputPin : public APin {
        public:
            OutputPin(AComponent *component, std::size_t pin);
            void setLink(IComponent &other, std::size_t otherPin) override;
            Tristate compute() override;
            void reset() override;
            void dump() const override;
    };
}