/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** InputPin
*/

#pragma once

#include "APin.hpp"

namespace nts {
    class InputPin: public APin {
        public:
            InputPin(AComponent *component, std::size_t pin);
            void setLink(IComponent &other, std::size_t otherPin) override;
            Tristate compute() override;
            void reset() override;
            void dump() const override;

        private:
            Tristate _value;
            bool _computed;
    };
}