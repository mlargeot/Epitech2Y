/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** AComponent
*/

#pragma once

#include <memory>
#include <vector>
#include "IComponent.hpp"

namespace nts {
    class AComponent : public IComponent {
    public:
        explicit AComponent(ComponentType type);
        virtual ~AComponent() = default;
        virtual Tristate compute(std::size_t pin) = 0;
        virtual void reset() = 0;
        [[nodiscard]] ComponentType getType() const;
        virtual void dump() const = 0;

    protected:
        ComponentType _type;
    };
}