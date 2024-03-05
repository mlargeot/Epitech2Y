/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** corp
*/

#pragma once

#include <Parser/Parser.hpp>
#include <Circuit/Circuit.hpp>
#include <Components/IComponent.hpp>
#include <map>
#include <string>
#include <vector>

namespace nts {

    class Simulation {
    public:
        Simulation();
        Circuit &getCircuit();
        Parser &getParser();

        void loadComponents();
        void display();
        void simulate();
        void reset();

    protected:
        Parser _parser;
        size_t _ticks;
        Circuit _circuit;
    };
}

int startShell(nts::Simulation &simulation);
