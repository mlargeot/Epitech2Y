/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Or
*/

#pragma once

#include <Components/IComponent.hpp>
#include "AChipset.hpp"

namespace nts {
    class Or : public AChipset {
        public:
            Or();
            ~Or();

            Tristate compute(std::size_t pin) override;
            void dump() const override;
    };
}