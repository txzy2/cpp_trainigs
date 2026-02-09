#include <vector>
#include <random>
#include <algorithm>

#include "../include/arrays.h"

std::vector<int> Arrays::generateArray()
{
    if (this->params.size <= 0 || this->params.min > this->params.max || this->params.min < 0 || this->params.max < 0)
    {
        std::cerr << "Invalid parameters for array generation." << std::endl;
        return {};
    }

    std::vector<int> generatedArray(params.size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(params.min, params.max);

    for (auto &num : generatedArray)
        num = dist(gen);

    return generatedArray;
}

std::vector<int> Arrays::computeAdjacentDifferences(std::vector<int> &a)
{
    std::vector<int> differences(a.size() - 1);
    for (size_t i = 1; i < a.size(); i++)
    {
        differences[i - 1] = a[i] - a[i - 1];
    }
    return differences;
}

void Arrays::displayArray(const std::vector<int> &arr, const std::string &name) const
{
    std::cout << name << " array: [";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;
}

std::pair<int, int> Arrays::findLongestSequence(const std::vector<int> &a)
{
    if (a.empty())
        return std::make_pair(0, 0);

    int maxLength = 1, currentLength = 1, maxValue = a[0];

    for (size_t i = 1; i < a.size(); i++)
    {
        currentLength = (a[i] == a[i - 1]) ? currentLength + 1 : 1;

        if (currentLength > maxLength)
        {
            maxLength = currentLength;
            maxValue = a[i];
        }
    }

    return std::make_pair(maxValue, maxLength);
}