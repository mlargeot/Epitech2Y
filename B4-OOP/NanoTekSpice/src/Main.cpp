/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** main
*/

#include <iostream>
#include <Simulation/Simulation.hpp>

int main(int ac, char **av [[maybe_unused]]) {
    nts::Simulation simulation;

    if (ac < 2)
        return 84;
    try {
        nts::Parser &parser = simulation.getParser();
        parser.parseFile(av[1]);
        simulation.loadComponents();
        startShell(simulation);
        return 0;
    } catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        return 84;
    }
    return 0;
}
