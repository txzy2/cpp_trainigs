#ifndef ARRAYS_H
#define ARRAYS_H

#include <string>
#include <vector>
#include <iostream>

class Arrays
{

private:
    std::vector<int> arr;

    struct Params
    {
        int size;
        int min;
        int max;
    } params;

    bool isValidSize(int value) const
    {
        return value > 0;
    }

public:
    Arrays() = default;

    std::vector<int> generateArray();
    std::vector<int> computeAdjacentDifferences(std::vector<int> &a);

    void displayArray(const std::vector<int> &arr, const std::string &name) const;
    std::pair<int, int> findLongestSequence(const std::vector<int> &a);

    void setSize(int s) { params.size = s; }
    void setMin(int m) { params.min = m; }
    void setMax(int m) { params.max = m; }
};

#endif
