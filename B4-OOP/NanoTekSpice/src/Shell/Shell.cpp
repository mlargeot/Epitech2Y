/*
** EPITECH PROJECT, 2024
** nano
** File description:
** shell
*/

#include <iostream>
#include <algorithm>
#include <csignal>

#include "Shell.hpp"

bool Shell::_loop{false};

/*----------------------------------SHELL FUNCTIONS----------------------------------*/

int startShell(nts::Simulation &simulation)
{
    Shell newShell(simulation);

    while (!std::cin.eof()) {
        std::cout << "> ";
        if (newShell.execCommand())
            break;
    }
    return 0;
}

std::string getInputCommand(void)
{
    std::string input;
    std::string finalInput;

    std::getline(std::cin, input);
    size_t start = input.find_first_not_of(' ');
    if (start != std::string::npos) {
        std::string newInput = input.substr(start);
        size_t end = newInput.find(' ');
        if (end != std::string::npos)
            finalInput = newInput.substr(0, end);
        else
            finalInput = newInput;
    }
    return finalInput;
}

/*----------------------------------SHELL CLASS METHODS----------------------------------*/

int Shell::execCommand()
{
    std::string command = getInputCommand();

    if (command.empty())
        return 0;
    if (command_list.find(command) != command_list.end())
        return command_list[command]();
    size_t pos = command.find('=');
    if (pos == std::string::npos)
        return 0;
    return this->handle_input(command, pos);
}

int Shell::exit()
{
    return 1;
}

int Shell::display()
{
    this->_simulation.display();
    return 0;
}

int Shell::simulate()
{
    this->_simulation.simulate();
    return 0;
}


void Shell::stopLoop(int signal [[maybe_unused]])
{
    _loop = false;
}

int Shell::loop()
{
    this->_loop = true;

    std::signal(SIGINT, this->stopLoop);
    while (this->_loop) {
        this->simulate();
        this->display();
    }
    std::signal(SIGINT, SIG_DFL);
    return 0;
}

int Shell::handle_input(std::string command, size_t pos)
{
    std::string key = command.substr(0, pos);
    std::string value = command.substr(pos + 1, command.size() - 1);

    if (key.empty() || value.empty() || (value != "U" && value != "1" && value != "0"))
        return 0;
    nts::Circuit &circuit = this->_simulation.getCircuit();
    std::map<std::string, std::shared_ptr<nts::Input>> circuit_inputs = circuit.getInputs();
    if (circuit_inputs.empty() || circuit_inputs.find(key) == circuit_inputs.end())
        return 0;
    if (value == "U")
        circuit_inputs[key]->setNextValue(nts::T_UNDEFINED);
    else if (value == "1")
        circuit_inputs[key]->setNextValue(nts::T_TRUE);
    else
        circuit_inputs[key]->setNextValue(nts::T_FALSE);
    return 0;
}
