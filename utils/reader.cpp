#include "reader.h"

#include <cmath>
#include <iostream>
#include <sstream>

#include "../utils/constants.h"

float IoReader::readLine(const std::string& paramName) {
    double value;
    std::string line;

    while (true) {
        std::cout << "Paste param (" << RED << paramName << RESET << ") -> ";
        std::getline(std::cin, line);

        std::istringstream iss(line);

        if (iss >> value && value >= 1 && std::isfinite(value)) {
            return static_cast<float>(value);
        }

        std::cerr << RED << "Ошибка ввода. Попробуй снова." << RESET << std::endl;
    }
}
