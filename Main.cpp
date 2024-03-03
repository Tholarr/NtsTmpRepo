/*
** EPITECH PROJECT, 2024
** NtsTmpRepo
** File description:
** Main
*/

#include "AComponent.hpp"
#include <fstream>
#include <iostream>
#include <regex>

void displayHelpMsg(int n) {
    std::cout << "Usage: ./nanotekspice file.nts" << std::endl << std::endl;
    std::cout << "SIMULATOR:" << std::endl;
    std::cout << "exit          Closes the program." << std::endl;
    std::cout << "display       Prints the current tick and the value of all inputs and outputs the standard output," << std::endl;
    std::cout << "              each sorted by name in ASCII order." << std::endl;
    std::cout << "input=value   Changes the value of an input. Possible value are 0, 1 and U." << std::endl;
    std::cout << "              This also apply to clocks." << std::endl;
    std::cout << "simulate      Simulate a tick of the circuit." << std::endl;
    std::cout << "loop          Continuously runs the simulation (simulate, display, simulate, ...)" << std::endl;
    std::cout << "              without displaying a prompt, until SIGINT (CTRL+C) is received." << std::endl;
    exit(n);
}

void argsErrorHandling(int ac, char **av) {
    if (ac != 2)
        displayHelpMsg(84);
    if (av[1] == std::string("--help"))
        displayHelpMsg(0);
    if (av[1] == std::string("-h"))
        displayHelpMsg(0);
    std::string filename = av[1];
    if (filename.length() < 4)
        displayHelpMsg(84);
    if (filename.substr(filename.length() - 4) != ".nts")
        displayHelpMsg(84);
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Invalid file \"" << filename << "\"" << std::endl;
        exit(84);
    }
    file.close();
    return;
}

std::vector<std::tuple<std::string, std::string>> readChipsets(const std::string& fileName) {
    std::ifstream file(fileName);
    std::vector<std::tuple<std::string, std::string>> chipsets;
    std::string line;
    bool inChipsetsSection = false;

    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        if (line == ".chipsets:") {
            inChipsetsSection = true;
            continue;
        }
        if (inChipsetsSection) {
            int colon_pos = line.find(' ');
            int comment = line.find('#');
            if (line == ".links:") {
                break;
            } else if (comment == -1) {
                std::string type = line.substr(0, colon_pos);
                std::string name = line.substr(colon_pos + 1);
                chipsets.push_back(std::make_tuple(type, name));
            }
        }
    }
    file.close();
    return chipsets;
}

std::vector<std::tuple<std::string, std::string>> readLinks(const std::string& fileName) {
    std::ifstream file(fileName);
    std::vector<std::tuple<std::string, std::string>> links;
    std::string line;
    bool inLinksSection = false;

    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        if (line == ".links:") {
            inLinksSection = true;
            continue;
        }
        if (inLinksSection) {
            int colon_pos = line.find(' ');
            int comment = line.find('#');
            if (line == ".links:") {
                break;
            } else if (comment == -1) {
                std::string type = line.substr(0, colon_pos);
                std::string name = line.substr(colon_pos + 1);
                links.push_back(std::make_tuple(type, name));
            }
        }
    }
    file.close();
    return links;
}

int main(int ac, char **av) {
    std::unique_ptr<nts::AComponent> data = std::make_unique<nts::AComponent>();
    std::vector<std::tuple<std::string, std::string>> chipsets;
    std::vector<std::tuple<std::string, std::string>> links;
    argsErrorHandling(ac, av);
    chipsets = readChipsets(av[1]);
    links = readLinks(av[1]);
    // return data->run();

    for (const auto& tuple : chipsets) {
        std::cout << "(" << std::get<0>(tuple) << ", " << std::get<1>(tuple) << ")" << std::endl;
    }

    return 0;
}
