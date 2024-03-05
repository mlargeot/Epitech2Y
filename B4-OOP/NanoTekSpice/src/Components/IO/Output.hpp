/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Output
*/

#pragma once

#include "Components/Pin/InputPin.hpp"

namespace nts {
    class Output : public AComponent {
        public:
            Output();
            Tristate compute(std::size_t pin) override;
            void setValue(Tristate value);
            [[nodiscard]] Tristate getValue() const;
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
            void reset() override;
            void dump() const override;
        protected:
            Tristate _value;
            InputPin _pin;
    };
}