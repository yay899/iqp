/**
 * @file Instance.hpp
 * @author Maximilian Thompson (mhompson2@wpi.edu)
 * @author James Ternent (jwternent@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2019-11-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include <random>
#include <vector>

#include "Data.hpp"

// These represent the range of outputs that make a correct diagnosis.
const double secretHigh = 4.0;
const double secretLow = -2.0;

// These represent the range of outputs that are considered acceptable by the tests.
const double unitHigh = secretHigh + 0.1;
const double unitLow = secretLow + 0.1;

// These represent default starting weights.
const double initialMean = 1.0;
const double initialStddev = 1.0;

// This represents the number of jobs performed per day.
const int jobs = 100;

extern std::default_random_engine rng;

class Instance {
public:

    Instance(double mean = initialMean, double stddev = initialStddev);

    inline bool needsDev() { return devTimer > 0; }
    inline void addDev(int days) { devTimer += days; }

    /**
     * @brief This represents new weights being deployed.
     * 
     */
    inline void deploy() {
        curMean = mean;
        curStddev = stddev;
    }

    /**
     * @brief This represents performing day to day work.
     * 
     */
    double work();

    /**
     * @brief This represents time spent being diagnosed for error following
     * a failed unit test.
     * 
     */
    inline void develop() { devTimer--; }

    /**
     * @brief This represents using data accumulated by the machine instance
     * to attempt to improve weights.
     * 
     */
    void learn();

    /**
     * @brief This represents performing unit tests, and returns a bool
     * representing either success or failure.
     * 
     * @return double The rate of success.
     */
    bool const performTests();

    

private:
    double mean;           // The mean to use for unit tests.
    double curMean;        // The mean used in deployment.
    double stddev;         // The standard devation to use for unit tests.
    double curStddev;      // The standard deviation used in deployment.
    std::vector<Data> dat; // Stored data for learning.
    int devTimer;          // The number of days left in development cycle.

};