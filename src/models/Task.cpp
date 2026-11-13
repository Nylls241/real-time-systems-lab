/**
 * @file Task.cpp
 * @brief Implementation of the Task class representing a periodic task in a real-time system.
 */

#include "Task.hpp"

/**
 * @brief Constructs a new Task object.
 * 
 * Initializes the task's name, period, execution time, and deadline.
 *
 * @param name Identification string for the task.
 * @param period Time interval between task releases in milliseconds.
 * @param executionTime Worst-case execution time (WCET) required in milliseconds.
 * @param deadline Relative deadline within which the task must complete execution in milliseconds.
 */
Task::Task(const std::string& name,
           unsigned int period,
           unsigned int executionTime,
           unsigned int deadline)
    : name(name),
      period(period),
      executionTime(executionTime),
      deadline(deadline) {
}

/**
 * @brief Validates the timing constraints of the task.
 *
 * Checks if the task satisfies the constrained deadline condition:
 * - Execution time must be strictly greater than 0.
 * - Execution time must not exceed the deadline ($C \le D$).
 * - Deadline must not exceed the period ($D \le T$).
 *
 * @return true If parameters satisfy $0 < C \le D \le T$, false otherwise.
 */
bool Task::isValid() const {
    // Execution time must be non-zero and fit within the deadline,
    // which in turn must fit within the period interval.
    return (executionTime > 0) &&
           (executionTime <= deadline) &&
           (deadline <= period);
}

/**
 * @brief Getter for the task name.
 * 
 * @return std::string The name of the task.
 */
std::string Task::getName() const {
    return name;
}

/**
 * @brief Getter for the period.
 * 
 * @return unsigned int Period in milliseconds.
 */
unsigned int Task::getPeriod() const {
    return period;
}

/**
 * @brief Getter for the worst-case execution time.
 * 
 * @return unsigned int Execution time in milliseconds.
 */
unsigned int Task::getExecutionTime() const {
    return executionTime;
}

/**
 * @brief Getter for the task deadline.
 * 
 * @return unsigned int Relative deadline in milliseconds.
 */
unsigned int Task::getDeadline() const {
    return deadline;
}
