/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** PinMap
*/

#pragma once

#include <map>
#include <functional>
#include "APin.hpp"
#include <memory>

namespace nts {
    class PinMap {
        std::map<std::size_t, std::unique_ptr<APin>> _pins;

    public:
        PinMap() = default;
        ~PinMap() = default;

        void addInput(AComponent *component, std::size_t pin);
        void addOutput(AComponent *component, std::size_t pin);
        bool isValid(std::size_t pin) const;
        bool isLinked(std::size_t pin) const;
        Tristate compute(std::size_t pin);
        using GateFunc = std::function<Tristate(Tristate, Tristate)>;
        Tristate compute(const GateFunc &gate, std::size_t pinA, std::size_t pinB);
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
        void reset();
        void dump() const;
    };

}