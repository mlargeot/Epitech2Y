/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Input
*/

#pragma once

#include <Components/AComponent.hpp>
#include <Components/Pin/OutputPin.hpp>

namespace nts {
    class Input : public AComponent {
        public:
            explicit Input(ComponentType type, Tristate value);
            Tristate compute(std::size_t pin) override;
            [[nodiscard]] Tristate getValue() const;
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
            virtual void updateState();
            virtual void setValue(Tristate value);
            virtual void setNextValue(Tristate value);
            void reset() override;
            void dump() const override;
        protected:
            Tristate _value;
            Tristate _nextValue;
            OutputPin _pin;
    };
}
