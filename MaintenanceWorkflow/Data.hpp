/**
 * @file Data.hpp
 * @author Maximilian Thompson (mthompson2@wpi.edu)
 * @author James Ternent (jwternent@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2019-11-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

class Data {
public:
    // Change in mean and standard deviation implied by data.
    const double dMean, dStddev;

    Data(double dMean, double dStddev);
    
};