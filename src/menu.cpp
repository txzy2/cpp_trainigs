#include "../include/menu.h"

#include <cstdlib>
#include <iostream>
#include <vector>

#include "../include/arrays.h"
#include "../include/math.h"
#include "../utils/constants.h"
#include "../utils/reader.h"

void Menu::initMenu() {
    menuItems = {{"Math.Sum", [this]() { add(); }},
                 {"Math.Multiplication", [this]() { mathMultiplication(); }},
                 {"Math.Division", [this]() { mathDivision(); }},
                 {"Math.Subtraction", [this]() { mathSubtraction(); }},
                 {"Arrays Operations", [this]() { arraysMenu(); }},
                 {"Exit", [this]() { exit(); }}};
}

void Menu::arraysMenu() {
    std::cout << std::endl << RED << "=== ARRAYS ===" << RESET << std::endl;

    Arrays arrays;
    arrays.setSize(static_cast<int>(reader.readLine("array size")));
    arrays.setMin(static_cast<int>(reader.readLine("min value")));
    arrays.setMax(static_cast<int>(reader.readLine("max value")));

    std::vector<int> generatedArray = arrays.generateArray();
    std::cout << std::endl;

    arrays.displayArray(generatedArray, "Main (generated)");
    std::vector<int> differences = arrays.computeAdjacentDifferences(generatedArray);
    arrays.displayArray(differences, "Differences");

    Arrays newArraySeq;
    newArraySeq.setSize(50);
    newArraySeq.setMin(0);
    newArraySeq.setMax(1);

    std::cout << std::endl;
    std::vector<int> seqArray = newArraySeq.generateArray();
    newArraySeq.displayArray(seqArray, "Sequence");

    std::pair<int, int> longestSequence = arrays.findLongestSequence(seqArray);

    std::cout << "Longest sequence value: " << RED << longestSequence.first << RESET
              << ", length: " << RED << longestSequence.second << RESET << std::endl;

    this->getMenu();
}

void Menu::getMenu() {
    this->initMenu();

    std::cout << std::endl << GREEN << "=== MAIN MENU ===" << RESET << std::endl;
    for (size_t i = 0; i < this->menuItems.size(); i++) {
        std::cout << RED << i + 1 << ". " << RESET << this->menuItems[i].title << std::endl;
    }
    std::cout << "============" << std::endl;
}

void Menu::handleMenuChoice(int choice) {
    if (choice < 1 || choice > this->menuItems.size()) {
        std::cout << "Invalid choice" << std::endl;
        return;
    }

    this->menuItems[choice - 1].action();
}

void Menu::exit() {
    std::cout << "Good bye!" << std::endl;
    this->running = false;
}

Menu::Params Menu::readLine() {
    Params params;
    params.first = reader.readLine("first");
    params.second = reader.readLine("second");
    return params;
}

void Menu::add() {
    Params params = this->readLine();
    Math mathClass(params.first, params.second);

    std::cout << std::endl << RED "=== RESULT ===" << RESET << std::endl;
    std::cout << params.first << " + " << params.second << " = " << mathClass.add() << std::endl;

    this->getMenu();
}

void Menu::mathMultiplication() {
    Params params = this->readLine();
    Math mathClass(params.first, params.second);

    std::cout << std::endl << RED "=== RESULT ===" << RESET << std::endl;
    std::cout << params.first << " * " << params.second << " = " << mathClass.multiplication()
              << std::endl;

    this->getMenu();
}

void Menu::mathDivision() {
    Params params = this->readLine();
    Math mathClass(params.first, params.second);

    try {
        std::cout << std::endl << RED "=== RESULT ===" << RESET << std::endl;
        std::cout << BOLD_MAGENTA << params.first << RESET << " / " << BOLD_MAGENTA << params.second
                  << RESET << " = " << BOLD_MAGENTA << mathClass.division() << RESET << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    this->getMenu();
}

void Menu::mathSubtraction() {
    Params params = this->readLine();
    Math mathClass(params.first, params.second);

    std::cout << std::endl << RED "=== RESULT ===" << RESET << std::endl;
    std::cout << params.first << " - " << params.second << " = " << mathClass.subtraction()
              << std::endl;

    this->getMenu();
}
