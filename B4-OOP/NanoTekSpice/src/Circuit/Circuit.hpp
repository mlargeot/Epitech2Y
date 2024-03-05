/*
** EPITECH PROJECT, 2024
** nanotekspice
** File description:
** Circuit
*/

#pragma once

#include <string>
#include <map>

#include <Parser/Parser.hpp>
#include <Components/AComponent.hpp>
#include <Components/IO/Input.hpp>
#include <Components/IO/Clock.hpp>
#include <Components/IO/Output.hpp>
#include "Components/ComponentFactory.hpp"

namespace nts {
    class Circuit {
        public:
            Circuit();
            ~Circuit() = default;

            void createComponents(const std::vector<nts::Chipset>& components);
            void createLinks(const std::vector<nts::Link>& links);

            std::map<std::string, std::shared_ptr<nts::AComponent>> &getComponents();
            std::map<std::string, std::shared_ptr<nts::Input>> &getInputs();
            std::map<std::string, std::shared_ptr<nts::Clock>> &getClocks();
            std::map<std::string, std::shared_ptr<nts::Output>> &getOutputs();

        protected:
            std::unique_ptr<nts::ComponentFactory> _factory;
            std::map<std::string, std::shared_ptr<nts::AComponent>> _components;
            std::map<std::string, std::shared_ptr<nts::Input>> _inputs;
            std::map<std::string, std::shared_ptr<nts::Clock>> _clocks;
            std::map<std::string, std::shared_ptr<nts::Output>> _outputs;
    };
}