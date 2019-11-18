/**
 * @file Instance.cpp
 * @author Maximilian Thompson (mthompson2@wpi.edu)
 * @author James Ternent (jwternent@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2019-11-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "Instance.hpp"

double Instance::work() {
    int successes = 0;
    std::normal_distribution<double> dst(curMean, curStddev);
    for (int i = 0; i < jobs; i++) {
        double res = dst(rng);
        if (res > secretLow && res < secretHigh) { successes++; }
    }

    return successes / jobs;
}

bool const Instance::performTests() {
    // Generate a normally distributed random number.
    std::normal_distribution<double> dst(mean, stddev);
    double res = dst(rng);

    if (res > unitLow && res < unitHigh) {
        return true;
    } else {
        return false;
    }
}