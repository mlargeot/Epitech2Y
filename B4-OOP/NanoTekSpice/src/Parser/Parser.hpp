/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Parser
*/

#pragma once

#include <string>
#include <vector>
#include <regex>

namespace nts {

    struct Chipset {
        std::string type;
        std::string name;
    };

    struct Link {
        std::string from;
        int fromPin;
        std::string to;
        int toPin;
    };

    class Parser {
        public:
            Parser();
            ~Parser() = default;

            class Error : public std::exception {
            public:
                Error(const char *error) noexcept : _err(error) {}
                const char *what() const noexcept override
                {
                    return _err;
                };
            private:
                const char *_err;   
            };

            void parseFile(const std::string& filename);
            bool parseComponents(std::string line);
            bool parseLinks(std::string line);

            void handleHeader(std::string line);
            void handleComponentName(Chipset chipset);
            void handleLinks(std::smatch linksMatch);
            std::vector<Chipset> getComponents() const;
            std::vector<Link> getLinks() const;

        private:
            bool _chipsetSection;
            bool _linksSection;
            std::vector<Chipset> _components;
            std::vector<Link> _links;
    };
}
