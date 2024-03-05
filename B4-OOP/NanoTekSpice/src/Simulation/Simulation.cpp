/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Simulation
*/

#include <iostream>

#include "Simulation.hpp"

nts::Simulation::Simulation() : _ticks(0) {}

void nts::Simulation::loadComponents()
{
    this->_circuit.createComponents(this->_parser.getComponents());
    this->_circuit.createLinks(this->_parser.getLinks());
}

nts::Circuit &nts::Simulation::getCircuit() {
    return this->_circuit;
}

nts::Parser &nts::Simulation::getParser() {
    return this->_parser;
}

void nts::Simulation::display() {
    std::cout << "tick: " << this->_ticks << std::endl;
    std::cout << "input(s):" << std::endl;
    std::map<std::string, std::shared_ptr<nts::Input>> circuit_inputs = this->_circuit.getInputs();
    for (const auto &[key, value] : circuit_inputs) {
        if(value->getType() == nts::ComponentType::C_TRUE || value->getType() == nts::ComponentType::C_FALSE)
            continue;
        if (value->getValue() == nts::T_UNDEFINED)
            std::cout << "  " <<  key << ": U" << std::endl;
        else
            std::cout << "  " <<  key << ": " << value->getValue() << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    std::map<std::string, std::shared_ptr<nts::Output>> circuit_outputs = this->_circuit.getOutputs();
    for (const auto &[key, value] : circuit_outputs) {
        if (value->getValue() == nts::T_UNDEFINED)
            std::cout << "  " <<  key << ": U" << std::endl;
        else
            std::cout << "  " <<  key << ": " << value->getValue() << std::endl;
    }
}

void nts::Simulation::reset() {
    for (auto &component : _circuit.getComponents()) {
        component.second->reset();
    }
}

void nts::Simulation::simulate() {
    reset();

    for (auto &_input : _circuit.getInputs()) {
        _input.second->updateState();
    }
    for (auto &_output : _circuit.getOutputs()) {
        _output.second->compute(1);
    }
    this->_ticks += 1;
    for (auto &clock : _circuit.getClocks()) {
        clock.second->reverseValue();
    }
}
