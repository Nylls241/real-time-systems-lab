#ifndef SCENARIO_LOADER_HPP
#define SCENARIO_LOADER_HPP

#include <string>

#include "../models/TaskSet.hpp"
#include "../models/Task.hpp"

/**
 * @class ScenarioLoader
 * @brief Loads predefined scenarios and creates TaskSet objects.
 *
 * A scenario describes a collection of periodic tasks
 * used for simulation experiments.
 */
class ScenarioLoader {

public:

    /**
     * @brief Loads a scenario from a file.
     *
     * @param filename Path to the scenario configuration file.
     * @return A TaskSet containing the loaded tasks.
     */
    TaskSet loadScenario(const std::string& filename) const {
        // I don't have the syntax unfornately, but 
        // Here is the logic read the file (so the file has to respect a format no?)
        // each thing in the file become a task in such of kind 
    };
};

#endif // SCENARIO_LOADER_HPP