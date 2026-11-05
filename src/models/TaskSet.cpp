/**
 * @file TaskSet.cpp
 * @brief Implementation of the TaskSet class managing a collection of periodic tasks.
 */

#include "TaskSet.hpp"

/**
 * @brief Adds a task to the collection.
 * 
 * Appends the given Task object to the internal vector storing tasks.
 *
 * @param task The task object to be added.
 */
void TaskSet::addTask(const Task& task)
{
    tasks.push_back(task);
}

/**
 * @brief Checks if the task set contains no tasks.
 * 
 * @return true If the underlying task collection is empty, false otherwise.
 */
bool TaskSet::isEmpty() const
{
    return tasks.empty();
}

/**
 * @brief Validates the whole task set.
 * 
 * A task set is considered valid if:
 * 1. It is not empty (contains at least one task).
 * 2. Every individual task in the set passes its own validation check (`task.isValid()`).
 *
 * @return true If the task set is non-empty and all tasks are valid, false otherwise.
 */
bool TaskSet::isValid() const
{
    // A task set must contain at least one task to be valid.
    if (isEmpty())
    {
        return false;
    }

    // Iterate through all tasks and verify that each task meets its timing constraints.
    for (const Task& task : tasks)
    {
        if (!task.isValid())
        {
            return false; // Found an invalid task, early exit.
        }
    }

    return true;
}

/**
 * @brief Gets the total number of tasks in the set.
 * 
 * @return unsigned int Number of elements in the task vector.
 */
unsigned int TaskSet::getTaskCount() const
{
    return static_cast<unsigned int>(tasks.size());
}

/**
 * @brief Provides read-only (const) access to the underlying vector of tasks.
 * 
 * @return const std::vector<Task>& Constant reference to the task vector, avoiding deep copies.
 */
const std::vector<Task>& TaskSet::getTasks() const
{
    return tasks;
}
