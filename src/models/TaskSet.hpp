#ifndef TASK_SET_HPP
#define TASK_SET_HPP

#include <vector>
#include "Task.hpp"

/**
 * @brief Represents a collection of periodic tasks.
 *
 * A TaskSet allows the Experimenter to:
 * - Add tasks.
 * - Check whether the task set is empty.
 * - Validate all task parameters.
 * - Access the configured tasks.
 */
class TaskSet
{
private:
    std::vector<Task> tasks;

public:
    /**
     * @brief Adds a task to the task set.
     *
     * @param task Task to add.
     */
    void addTask(const Task& task);

    /**
     * @brief Checks whether the task set contains no tasks.
     *
     * @return true if the task set is empty.
     */
    bool isEmpty() const;

    /**
     * @brief Validates all tasks in the task set.
     *
     * @return true if the task set is not empty and
     *         every task has valid parameters.
     */
    bool isValid() const;

    /**
     * @brief Returns the number of tasks.
     *
     * @return Number of tasks in the collection.
     */
    unsigned int getTaskCount() const;

    /**
     * @brief Provides read-only access to the tasks.
     *
     * @return Constant reference to the task collection.
     */
    const std::vector<Task>& getTasks() const;
};

#endif