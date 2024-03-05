/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** ComponentFactory
*/

#include <stdexcept>
#include "ComponentFactory.hpp"
#include "Components/Chipsets/And.hpp"
#include "Components/Chipsets/Or.hpp"
#include "Components/Chipsets/Not.hpp"
#include "Components/Chipsets/Xor.hpp"
#include "Components/Chipsets/C4081.hpp"
#include "Components/Chipsets/C4001.hpp"
#include "Components/Chipsets/C4011.hpp"
#include "Components/Chipsets/C4030.hpp"
#include "Components/Chipsets/C4069.hpp"
#include "Components/Chipsets/C4071.hpp"

nts::ComponentFactory::ComponentFactory() {
    this->_inputs["input"] = &ComponentFactory::createInput;
    this->_inputs["clock"] = &ComponentFactory::createClock;
    this->_inputs["true"] = &ComponentFactory::createTrue;
    this->_inputs["false"] = &ComponentFactory::createFalse;
    this->_inputs["output"] = &ComponentFactory::createOutput;

    this->_chipsets["and"] = &ComponentFactory::createAnd;
    this->_chipsets["or"] = &ComponentFactory::createOr;
    this->_chipsets["not"] = &ComponentFactory::createNot;
    this->_chipsets["xor"] = &ComponentFactory::createXor;

    this->_chipsets["4081"] = &ComponentFactory::create4081;
    this->_chipsets["4001"] = &ComponentFactory::create4001;
    this->_chipsets["4011"] = &ComponentFactory::create4011;
    this->_chipsets["4030"] = &ComponentFactory::create4030;
    this->_chipsets["4069"] = &ComponentFactory::create4069;
    this->_chipsets["4071"] = &ComponentFactory::create4071;
}


std::shared_ptr<nts::AComponent> nts::ComponentFactory::newInput(const std::string &type, nts::Tristate value) {
    auto it = this->_inputs.find(type);
    if (it == this->_inputs.end())
        throw std::runtime_error("A component type is unknown.");
    return it->second(*this, value);
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::newChipset(const std::string &type, nts::Tristate value) {
    auto it = this->_chipsets.find(type);
    if (it == this->_chipsets.end())
        throw std::runtime_error("A component type is unknown.");
    return it->second(*this, value);
}



std::shared_ptr<nts::Input> nts::ComponentFactory::createInput(nts::Tristate value) const {
    return std::make_shared<Input>(ComponentType::C_INPUT, value);
}

std::shared_ptr<nts::Output> nts::ComponentFactory::createOutput(nts::Tristate) const {
    return std::make_shared<Output>();
}

std::shared_ptr<nts::True> nts::ComponentFactory::createTrue(nts::Tristate) const {
    return std::make_shared<True>();
}

std::shared_ptr<nts::False> nts::ComponentFactory::createFalse(nts::Tristate) const {
    return std::make_shared<False>();
}

std::shared_ptr<nts::Clock> nts::ComponentFactory::createClock(nts::Tristate state) const {
    return std::make_shared<Clock>(state);
}



std::unique_ptr<nts::AComponent> nts::ComponentFactory::createAnd(Tristate) const {
    return std::make_unique<And>();
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::createOr(Tristate) const {
    return std::make_unique<Or>();
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::createNot(nts::Tristate) const {
    return std::make_unique<Not>();
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::createXor(nts::Tristate) const {
    return std::make_unique<Xor>();
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::create4081(nts::Tristate) const {
    return std::make_unique<C4081>();
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::create4001(nts::Tristate) const {
    return std::make_unique<C4001>();
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::create4011(nts::Tristate) const {
    return std::make_unique<C4011>();
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::create4030(nts::Tristate) const {
    return std::make_unique<C4030>();
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::create4069(nts::Tristate) const {
    return std::make_unique<C4069>();
}

std::unique_ptr<nts::AComponent> nts::ComponentFactory::create4071(nts::Tristate) const {
    return std::make_unique<C4071>();
}
