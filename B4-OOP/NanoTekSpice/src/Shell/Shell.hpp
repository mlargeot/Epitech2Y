/*
** EPITECH PROJECT, 2024
** Nano
** File description:
** Shell
*/

#pragma once

#include <unordered_map>
#include <map>
#include <functional>
#include <string>

#include <Simulation/Simulation.hpp>
#include <Circuit/Circuit.hpp>
#include <Components/IComponent.hpp>

class Shell {
    public:
        Shell(nts::Simulation &simulation) : _simulation(simulation)
        {
            command_list["display"] = [this](){return this->display();};
            command_list["exit"] = [this](){return this->exit();};
            command_list["simulate"] = [this](){return this->simulate();};
            command_list["loop"] = [this](){return this->loop();};
        };
        ~Shell() = default;

        int execCommand();
        int display();
        int exit();
        int simulate();
        int loop();
        int handle_input(std::string command, size_t pos);
        static void stopLoop(int signal [[maybe_unused]]);

    private:
        static bool _loop;
        nts::Simulation &_simulation;
        std::map<std::string, std::function<int()>> command_list;
};
