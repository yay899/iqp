/**
 * @file main.cpp
 * @author Maximilian Thompson (mthompson2@wpi.edu)
 * @author James Ternent (jwternent@wpi.edu)
 * @brief 
 * @version 0.1
 * @date 2019-11-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <iostream>
#include <vector>

#include "Instance.hpp"

const int numberOfInstances = 20;
const int numberOfDevTeams = 3;
const int numberOfDays = 300;

int main(int argc, char** argv) {
    std::cout << "Running isolated instances sim..." << std::endl;
    
    std::vector<Instance*> instances();
    for (int i = 0; i < numberOfInstances; i++) {
        instances.push_back(new Instance())
    }

    std::vector<Instance*> devQueue();

    for (int i = 0; i < numberOfDays; i++) {
        for (auto& it : instances) {
            if (!it->needsDev()) {
                it->deploy();
            }

            it->work();
        }

        // Develop as many instances as there are available dev teams.
        auto& it = devQueue.begin();
        for (int j = 0; j < numberOfDevTeams && it < devQueue.end(); j++) {
            it->develop();

            if (it->needsDev()) {
                // If it still needs more dev time, leave it in the queue.
                continue;
            } else {
                // Otherwise remove it from the queue and set the iterator appropriately.
                it = devQueue.erase(it);
            }
        }
    }

    for (auto& it : instances) {
        delete it;
        it = instances.erase(it);
    }

    for (auto& it : devQueue) {
        it = devQueue.erase(it);
    }

    std::cout << "Running global instance sim..." << std::endl;

    return 0;
}