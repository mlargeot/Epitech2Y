/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-morgan.largeot
** File description:
** Parser
*/

#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <regex>
#include <Simulation/Simulation.hpp>
#include "Parser.hpp"


/*---------------------------------------------------PARSER METHODS---------------------------------------------------*/

nts::Parser::Parser()
{
    this->_linksSection = false;
    this->_chipsetSection = false;
}

std::vector<nts::Chipset> nts::Parser::getComponents() const
{
    return this->_components;
}

std::vector<nts::Link> nts::Parser::getLinks() const
{
    return this->_links;
}

void nts::Parser::handleComponentName(Chipset chipset)
{
    for (size_t i = 0; i < this->_components.size(); i++) {
        if (chipset.name == this->_components[i].name)
            throw nts::Parser::Error("Same name between two components.");
    }
    return;
}

bool nts::Parser::parseComponents(std::string line)
{
    std::regex chipsetSectionPattern("^.chipsets:\\s*(?:#.*)?$");
    std::regex chipsetPattern("\\s*(\\w+)\\s+(\\w+)(?:\\s*#.*)?");

    std::smatch chipsetSectionMatch;
    if (std::regex_match(line, chipsetSectionMatch, chipsetSectionPattern)) {
        this->_chipsetSection = true;
        return true;
    }
    if (this->_chipsetSection && !this->_linksSection) {
        std::smatch chipsetMatch;
        if (std::regex_match(line, chipsetMatch, chipsetPattern)) {
                Chipset chipset;
                chipset.type = chipsetMatch[1];
                chipset.name = chipsetMatch[2];
                this->handleComponentName(chipset);
                this->_components.push_back(chipset);
        } else if (line.empty() || line == ".links:" || line[0] == '#') {
            return false;
        } else {
            throw nts::Parser::Error("Syntax error.");
        }
    }
    return false;
}

void nts::Parser::handleLinks(std::smatch linksMatch)
{
    bool verif = false;
    for (size_t i = 0; i < this->_components.size(); i++) {
        if (linksMatch[1] == this->_components[i].name)
            verif = true;
    }
    if (!verif)
        throw nts::Parser::Error("Unknown component.");
    verif = false;
    for (size_t i = 0; i < this->_components.size(); i++) {
        if (linksMatch[3] == this->_components[i].name)
            verif = true;
    }
    if (!verif)
        throw nts::Parser::Error("Unknown component.");
}

bool nts::Parser::parseLinks(std::string line)
{
    std::regex linksSectionPattern("^.links:\\s*(?:#.*)?$");
    std::regex linksPattern("\\s*(\\w+):(\\d+)\\s+(\\w+):(\\d+)(?:\\s*#.*)?");
    
    std::smatch linksSectionMatch;
    if (std::regex_match(line, linksSectionMatch, linksSectionPattern)) {
        this->_linksSection = true;
        return true;
    }
    if (this->_linksSection && this->_chipsetSection) {
        std::smatch linksMatch;
        if (std::regex_match(line, linksMatch, linksPattern)) {
            Link link;
            this->handleLinks(linksMatch);
            link.from = linksMatch[1];
            link.fromPin = std::stoi(linksMatch[2]);
            link.to = linksMatch[3];
            link.toPin = std::stoi(linksMatch[4]);
            this->_links.push_back(link);
        } else if (line.empty() || line[0] == '#') {
            return false;
        } else {
            throw nts::Parser::Error("Syntax error.");
        }
    }
    return false;
}

void nts::Parser::handleHeader(std::string line)
{
    if (!this->_chipsetSection && !this->_linksSection) {
        if (line.empty())
            return;
        if (line[0] != '#') {
            throw nts::Parser::Error("Syntax error.");
        }
    }
}

void nts::Parser::parseFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw nts::Parser::Error("Invalid file.");
    std::string line;

    while (std::getline(file, line)) {
        if(this->parseComponents(line))
            continue;
        if (this->parseLinks(line))
            continue;
        this->handleHeader(line);
    }
    if (!this->_chipsetSection || !this->_linksSection)
        throw nts::Parser::Error("Syntax error.");
    if (this->_components.empty())
        throw nts::Parser::Error("No chipset.");
}
