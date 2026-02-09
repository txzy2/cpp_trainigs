#ifndef MATH_H
#define MATH_H

class Math
{
private:
    float first;
    float second;

public:
    Math(float first, float second) : first(first), second(second) {}

    float add() { return first + second; }
    float multiplication() { return first * second; }
    float division() { return second != 0 ? first / second : 0; }
    float subtraction() { return first - second; }
};

#endif
