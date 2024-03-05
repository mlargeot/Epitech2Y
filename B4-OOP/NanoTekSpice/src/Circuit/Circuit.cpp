/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** Circuit
*/

#include <iostream>

#include "Circuit.hpp"

/*----------------------------------CIRCUIT CLASS METHODS----------------------------------*/

void nts::Circuit::createComponents(const std::vector<nts::Chipset> &components) {
    for (const auto &i : components) {
        std::shared_ptr<AComponent> component;

        if (i.type == "input") {
            std::shared_ptr<Input> input =  this->_factory->createInput(nts::T_UNDEFINED);

            this->_inputs[i.name] = input;
            component = input;
        } else if (i.type == "output") {
            std::shared_ptr<Output> output =  this->_factory->createOutput(nts::T_UNDEFINED);

            this->_outputs[i.name] = output;
            component = output;
        } else if (i.type == "clock") {
            std::shared_ptr<Clock> clock = this->_factory->createClock(nts::T_UNDEFINED);

            this->_clocks[i.name] = clock;
            this->_inputs[i.name] = clock;
            component = clock;
        } else if (i.type == "true") {
            std::shared_ptr<True> trueComponent = this->_factory->createTrue(nts::T_TRUE);

            this->_inputs[i.name] = trueComponent;
            component = trueComponent;
        } else if (i.type == "false") {
            std::shared_ptr<False> falseComponent = this->_factory->createFalse(nts::T_FALSE);

            this->_inputs[i.name] = falseComponent;
            component = falseComponent;
        } else {
            component = this->_factory->newChipset(i.type, nts::T_UNDEFINED);
        }
        this->_components[i.name] = component;
    }
}

void nts::Circuit::createLinks(const std::vector<nts::Link> &links)
{
    for (const auto & link : links) {
        std::string input_name = link.from;
        std::shared_ptr<AComponent> input_comp = this->_components[input_name];
        std::string output_name = link.to;
        std::shared_ptr<AComponent> output_comp = this->_components[output_name];

        if (input_comp == nullptr || output_comp == nullptr)
            continue;
        output_comp->setLink(link.toPin, *input_comp, link.fromPin);
        if (input_comp->getType() == ComponentType::C_TRUE || input_comp->getType() == ComponentType::C_FALSE) {
            std::shared_ptr<Output> out = std::dynamic_pointer_cast<Output>(output_comp);
            auto *output = dynamic_cast<Output *>(out.get());
            auto *input = dynamic_cast<Input *>(input_comp.get());

            if (out != nullptr)
                output->setValue(input->getValue());
        }
    }
}

std::map<std::string, std::shared_ptr<nts::AComponent>> & nts::Circuit::getComponents()
{
    return this->_components;
}

std::map<std::string, std::shared_ptr<nts::Input>> &nts::Circuit::getInputs()
{
    return this->_inputs;
}

std::map<std::string, std::shared_ptr<nts::Clock>> &nts::Circuit::getClocks()
{
    return this->_clocks;
}

std::map<std::string, std::shared_ptr<nts::Output>> &nts::Circuit::getOutputs()
{
    return this->_outputs;
}

nts::Circuit::Circuit() {
    this->_factory = std::make_unique<nts::ComponentFactory>();
}
