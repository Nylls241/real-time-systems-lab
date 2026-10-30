#ifndef TASK_HPP
#define TASK_HPP

#include <string>

/**
 * @brief Represents a periodic task with timing constraints.
 *
 * A task is characterized by:
 * - A name.
 * - A period (T).
 * - An execution time (C).
 * - A deadline (D).
 *
 * All timing values are expressed in milliseconds.
 */
class Task
{
private:
    std::string name;
    unsigned int period;
    unsigned int executionTime;
    unsigned int deadline;

public:
    /**
     * @brief Constructs a periodic task.
     *
     * @param name Name identifying the task.
     * @param period Time between two consecutive releases (ms).
     * @param executionTime Required execution time (ms).
     * @param deadline Maximum allowed completion time (ms).
     */
    Task(const std::string& name,
         unsigned int period,
         unsigned int executionTime,
         unsigned int deadline);

    /**
     * @brief Checks whether the task parameters are valid.
     *
     * For this simplified model, we assume constrained deadlines:
     * 0 < executionTime <= deadline <= period.
     *
     * @return true if the parameters are valid, false otherwise.
     */
    bool isValid() const;

    /**
     * @brief Returns the task name.
     */
    std::string getName() const;

    /**
     * @brief Returns the task period in milliseconds.
     */
    unsigned int getPeriod() const;

    /**
     * @brief Returns the execution time in milliseconds.
     */
    unsigned int getExecutionTime() const;

    /**
     * @brief Returns the deadline in milliseconds.
     */
    unsigned int getDeadline() const;
};

#endif