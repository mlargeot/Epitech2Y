/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Chipsets
*/

#pragma once

#include <Components/AComponent.hpp>
#include <Components/Pin/PinMap.hpp>
#include <Components/Gate.hpp>

namespace nts {
    class AChipset : public nts::AComponent {
        public:
            explicit AChipset(ComponentType type);
            ~AChipset() override = default;
            void reset() override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        protected:
            nts::PinMap _pins;
    };
}
