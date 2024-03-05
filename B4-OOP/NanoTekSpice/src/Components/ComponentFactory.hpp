/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** ComponentFactory
*/

#pragma once

#include <memory>
#include <map>
#include <functional>
#include "AComponent.hpp"
#include "Components/IO/Input.hpp"
#include "Components/IO/True.hpp"
#include "Components/IO/False.hpp"
#include "Components/IO/Clock.hpp"
#include "Components/IO/Output.hpp"

namespace nts {
    class ComponentFactory {
        public:
            ComponentFactory();
            ~ComponentFactory() = default;
            std::unique_ptr<AComponent> newChipset(const std::string &, Tristate value);
            std::shared_ptr<AComponent> newInput(const std::string &,Tristate value);

            // Chipsets Components //
            [[nodiscard]] std::unique_ptr<AComponent> createAnd(Tristate) const;
            [[nodiscard]] std::unique_ptr<AComponent> createOr(Tristate) const;
            [[nodiscard]] std::unique_ptr<AComponent> createNot(Tristate) const;
            [[nodiscard]] std::unique_ptr<AComponent> createXor(Tristate) const;

            [[nodiscard]] std::unique_ptr<AComponent> create4081(Tristate) const;
            [[nodiscard]] std::unique_ptr<AComponent> create4001(Tristate) const;
            [[nodiscard]] std::unique_ptr<AComponent> create4011(Tristate) const;
            [[nodiscard]] std::unique_ptr<AComponent> create4030(Tristate) const;
            [[nodiscard]] std::unique_ptr<AComponent> create4069(Tristate) const;
            [[nodiscard]] std::unique_ptr<AComponent> create4071(Tristate) const;
            //[[nodiscard]] std::unique_ptr<AComponent> create4008(Tristate) const;
            //[[nodiscard]] std::unique_ptr<AComponent> create4017(Tristate) const;
            //[[nodiscard]] std::unique_ptr<AComponent> create4040(Tristate) const;

            // Input Components //
            [[nodiscard]] std::shared_ptr<True> createTrue(Tristate) const;
            [[nodiscard]] std::shared_ptr<False> createFalse(Tristate) const;
            [[nodiscard]] std::shared_ptr<Clock> createClock(Tristate state) const;
            [[nodiscard]] std::shared_ptr<Output> createOutput(Tristate) const;
            [[nodiscard]] std::shared_ptr<Input> createInput(Tristate state) const;

        private:
            std::map<std::string, std::function<std::unique_ptr<AComponent>(ComponentFactory const &, Tristate)>> _chipsets;
            std::map<std::string, std::function<std::shared_ptr<AComponent>(ComponentFactory const &, Tristate)>> _inputs;
    };
}