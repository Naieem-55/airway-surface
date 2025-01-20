#pragma once

#include <random>

int randomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 generator(rd()); // Use Mersenne Twister engine
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}