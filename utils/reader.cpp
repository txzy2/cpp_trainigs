#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include "reader.h"

float IoReader::readLine(const std::string &paramName)
{
    double value;
    std::string line;

    while (true)
    {
        std::cout << "Paste param (" << paramName << ") -> ";
        std::getline(std::cin, line);

        std::istringstream iss(line);

        if (iss >> value && value >= 1 && std::isfinite(value))
        {
            return static_cast<float>(value);
        }

        std::cerr << "Ошибка ввода. Попробуй снова." << std::endl;
    }
}
