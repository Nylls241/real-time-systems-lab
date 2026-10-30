// Goal : Define class based on this main : define and configure sets of tasks subject to timing constraints;
// and this use-case : 
/* 3. Use Case Descriptions
UC-01 — Configure a Task Set

Brief description

The Experimenter defines a set of tasks subject to temporal constraints. Each task is characterized by parameters such as its period, execution time, and deadline.

Actor(s)

    Experimenter.

Context

The Experimenter prepares an experiment by defining the workload that will be simulated or executed under Linux.

Input data and preconditions

    Task parameters: period, execution time, and deadline.
    A task set may be created from scratch or loaded from an existing scenario, if this functionality is implemented.
    The experimental environment is available.

Output data and postconditions

    A configured task set is available for subsequent experiments.
    The task parameters have been checked for validity.
    Invalid configurations are reported to the Experimenter.

Main scenario

    The Experimenter selects the task-set configuration function.
    The system requests the task parameters.
    The Experimenter defines the tasks and their temporal constraints.
    The system validates the entered parameters.
    The system stores the configured task set.
    The system confirms that the task set is ready for an experiment.

Variants and error cases

    A1 — Invalid parameters: If a period, execution time, or deadline is missing or invalid, the system reports the problem and requests correction.
    A2 — Empty task set: If no task has been defined, the system refuses to validate the configuration.
    E1 — Configuration cannot be saved: If the configuration cannot be stored, the system reports an error and does not confirm successful completion.
*/
// How I have to this : A simplified application scenario of periodic data acquisition and processing, representing several (simulated) sensors, will serve as a case study. It will provide tasks with different frequencies and processing loads without requiring any specific hardware.
// Is it that I'm doing or not ? Did I change my use-case diagram if not ?
//But I can load a scenario : so, implement this feature ?