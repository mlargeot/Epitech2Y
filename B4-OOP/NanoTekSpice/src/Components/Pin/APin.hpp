/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Pin
*/

#pragma once

#include <Components/AComponent.hpp>

namespace nts {
    class APin {
        protected:
            AComponent &_component;
            std::size_t _pin;
            std::vector<std::pair<std::reference_wrapper<IComponent>, std::size_t>> _links;

        public:
            APin(AComponent *component, std::size_t id);
            ~APin() = default;

            [[nodiscard]] bool isLinked() const;
            bool isSelf(IComponent &component, std::size_t pin) const;
            bool isLinkedTo(IComponent &component, std::size_t pin) const;
            virtual void setLink(IComponent &other, std::size_t otherPin) = 0;
            virtual Tristate compute() = 0;
            virtual void reset() = 0;
            virtual void dump() const = 0;
    };
}