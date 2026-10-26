Use Case Specification — Real-Time Scheduling and Performance Analysis under Linux

1. Purpose

This document describes the use cases of the experimental environment developed as part of the project Real-Time Scheduling and Performance Analysis under Linux.

The system is designed to simulate the scheduling of task sets with temporal constraints, execute equivalent scenarios under Linux, collect timing measurements, and compare expected and observed behavior under different execution conditions.

The use cases are based on the project specification. Detailed workflows, preconditions, and error scenarios are proposed design choices where the specification does not define implementation details.

2. Use Case Diagram

@startuml
left to right direction
actor "Experimenter" as User
rectangle "Experimental Environment" {
  usecase "Configure a Task Set" as UC1
  usecase "Select a Scheduling Policy" as UC2
  usecase "Configure Load Conditions" as UC3
  usecase "Run a Scheduling Simulation" as UC4
  usecase "Execute a Scenario under Linux" as UC5
  usecase "Collect Timing Measurements" as UC6
  usecase "Save and Consult Results" as UC7
  usecase "Compare Simulation and\nReal Execution" as UC8
  usecase "Analyze Timing Deviations\nand Missed Deadlines" as UC9
}
User --> UC1
User --> UC2
User --> UC3
User --> UC4
User --> UC5
User --> UC7
User --> UC8
User --> UC9
UC4 ..> UC2 : <<include>>
UC5 ..> UC6 : <<include>>
UC8 ..> UC7 : <<include>>
UC9 ..> UC7 : <<include>>
@enduml

Primary actor: Experimenter.

External technical tools: stress-ng, ftrace, and perf may be used by the environment or during experiments. They are not modeled as actors in this diagram because they are treated as technical tools rather than independent users.

3. Use Case Descriptions

UC-01 — Configure a Task Set

Brief description

The Experimenter defines a set of tasks subject to temporal constraints. Each task is characterized by parameters such as its period, execution time, and deadline.

Actor(s)

* Experimenter.

Context

The Experimenter prepares an experiment by defining the workload that will be simulated or executed under Linux.

Input data and preconditions

* Task parameters: period, execution time, and deadline.
* A task set may be created from scratch or loaded from an existing scenario, if this functionality is implemented.
* The experimental environment is available.

Output data and postconditions

* A configured task set is available for subsequent experiments.
* The task parameters have been checked for validity.
* Invalid configurations are reported to the Experimenter.

Main scenario

1. The Experimenter selects the task-set configuration function.
2. The system requests the task parameters.
3. The Experimenter defines the tasks and their temporal constraints.
4. The system validates the entered parameters.
5. The system stores the configured task set.
6. The system confirms that the task set is ready for an experiment.

Variants and error cases

* A1 — Invalid parameters: If a period, execution time, or deadline is missing or invalid, the system reports the problem and requests correction.
* A2 — Empty task set: If no task has been defined, the system refuses to validate the configuration.
* E1 — Configuration cannot be saved: If the configuration cannot be stored, the system reports an error and does not confirm successful completion.

UC-02 — Select a Scheduling Policy

Brief description

The Experimenter selects the scheduling policy used to simulate the task set. The project specification mentions Earliest Deadline First (EDF) and Rate Monotonic (RM).

Actor(s)

* Experimenter.

Context

A scheduling policy is selected before running a scheduling simulation.

Input data and preconditions

* A configured task set.
* At least one scheduling policy supported by the implementation.

Output data and postconditions

* The selected scheduling policy is associated with the simulation configuration.

Main scenario

1. The Experimenter requests the scheduling-policy selection function.
2. The system displays the supported policies.
3. The Experimenter selects EDF or RM.
4. The system validates the selection.
5. The system records the selected policy for the simulation.

Variants and error cases

* A1 — Unsupported policy: If the selected policy is not supported, the system requests another selection.
* E1 — No policy selected: The system prevents the simulation from starting until a valid policy has been selected.

UC-03 — Configure Load Conditions

Brief description

The Experimenter defines the execution conditions under which a scenario will be tested, including possible CPU, memory, and input/output loads.

Actor(s)

* Experimenter.

Context

Load conditions are configured to study how system activity influences the temporal behavior of tasks during real execution.

Input data and preconditions

* A configured task set or scenario.
* The load parameters supported by the implementation.
* Access to the Linux environment in which the experiment will run.

Output data and postconditions

* A load configuration is associated with the experiment.
* The selected conditions can be reproduced in a later experiment if the configuration is saved.

Main scenario

1. The Experimenter opens the load-configuration function.
2. The system presents the supported load types and parameters.
3. The Experimenter selects the desired conditions, such as CPU, memory, or input/output load.
4. The system validates the configuration.
5. The system stores the load conditions for the experiment.

Variants and error cases

* A1 — No additional load: The Experimenter selects an execution without deliberately generated additional load.
* A2 — Unsupported load type: The system informs the Experimenter that the requested load type is unavailable.
* E1 — Invalid load configuration: The system rejects invalid parameters and requests correction.
* E2 — Load-generation tool unavailable: If a required tool such as stress-ng is unavailable, the system reports the limitation and does not claim that the requested load was applied.

UC-04 — Run a Scheduling Simulation

Brief description

The Experimenter simulates the scheduling of a configured task set using a selected scheduling policy to obtain reference behavior.

Actor(s)

* Experimenter.

Context

The simulation provides an expected scheduling behavior that can later be compared with real execution under Linux.

Input data and preconditions

* A valid task set.
* A selected scheduling policy, such as EDF or RM.
* A simulation configuration accepted by the system.

Output data and postconditions

* A simulation result representing the scheduled tasks.
* Reference timing information produced by the simulation.
* A result available for storage and comparison.

Main scenario

1. The Experimenter selects a task set.
2. The Experimenter selects the scheduling policy.
3. The Experimenter starts the simulation.
4. The system checks the simulation configuration.
5. The system simulates the scheduling behavior of the tasks.
6. The system generates the simulation results.
7. The system makes the results available for consultation and comparison.

Variants and error cases

* A1 — Configuration must be corrected: If the task set or policy is invalid, the system asks the Experimenter to correct the configuration before starting.
* E1 — Simulation failure: If the simulation cannot be completed, the system reports the error and does not present an incomplete result as a successful simulation.
* E2 — No result generated: If the simulation produces no usable result, the system informs the Experimenter.

UC-05 — Execute a Scenario under Linux

Brief description

The Experimenter runs a scenario under Linux to observe the actual temporal behavior of the tasks on a real system.

Actor(s)

* Experimenter.

Context

The execution reproduces a scenario corresponding to the task set used for simulation. Different system load conditions may be applied.

Input data and preconditions

* A valid scenario and task set.
* An available Linux execution environment.
* A valid execution configuration.
* Any required load-generation tools, if additional load has been requested.

Output data and postconditions

* An execution run has been attempted.
* Runtime information and available timing measurements are collected.
* The execution status is recorded.

Main scenario

1. The Experimenter selects a configured scenario.
2. The Experimenter selects the execution conditions.
3. The system checks that the configuration is valid.
4. The system prepares the Linux execution environment.
5. If configured, the system activates the requested additional load.
6. The system executes the scenario under Linux.
7. The system collects the available execution data.
8. The system records the execution status and makes the results available.

Variants and error cases

* A1 — Execution without additional load: The scenario is executed without deliberately generated extra load.
* A2 — Different Linux configuration: If available and configured, the Experimenter may execute the scenario under standard Linux or a PREEMPT_RT configuration.
* E1 — Execution cannot start: If the environment is unavailable or the configuration is invalid, the system reports the failure.
* E2 — Execution interrupted: If the run is interrupted, the system records the interruption and identifies the results as incomplete.
* E3 — Load-generation failure: If the requested load cannot be generated, the system reports the problem and records the conditions actually used, where possible.

UC-06 — Collect Timing Measurements

Brief description

The system collects timing measurements during real execution to characterize the temporal behavior of the tasks.

Actor(s)

* Experimenter (initiates the execution that produces the measurements).
* Technical instrumentation may include the C++ application and, where appropriate, Linux tools such as ftrace and perf.

Context

Measurements are collected during a Linux execution to study response times, their variability, and missed deadlines.

Input data and preconditions

* A scenario ready for execution.
* A running or completed execution that provides measurement data.
* The measurement mechanisms supported by the implementation.

Output data and postconditions

* Timing measurements associated with the execution.
* Available information about response times, variability, and missed deadlines.
* Measurement data ready to be saved and analyzed.

Main scenario

1. The system starts the configured measurement mechanisms.
2. The scenario executes under Linux.
3. The C++ application collects the timing data it supports.
4. If configured, additional information is collected using tools such as ftrace or perf.
5. The system associates the measurements with the corresponding execution.
6. The system makes the collected data available for storage and analysis.

Variants and error cases

* A1 — Partial instrumentation: If an optional instrumentation tool is unavailable, the system collects the measurements that remain available and reports the limitation.
* E1 — Measurement failure: If the primary measurement mechanism fails, the system reports that the measurements are incomplete or unavailable.
* E2 — Incomplete data: If some measurements are missing, the system marks the affected results so they are not mistaken for complete data.

UC-07 — Save and Consult Results

Brief description

The Experimenter saves experiment results and consults previously recorded simulation or execution data.

Actor(s)

* Experimenter.

Context

Recorded results provide a basis for reproducible experiments and subsequent comparisons.

Input data and preconditions

* A completed simulation or an execution that has produced usable results.
* A result set available to the environment.

Output data and postconditions

* Results are stored if saving succeeds.
* The Experimenter can consult the stored results.
* The results remain associated with their experiment configuration, to the extent supported by the implementation.

Main scenario

1. The Experimenter requests the results of an experiment.
2. The system displays the available results.
3. The Experimenter selects a result set.
4. The system displays the associated measurements and configuration information.
5. If the Experimenter requests storage, the system saves the results.
6. The system confirms whether storage succeeded.

Variants and error cases

* A1 — No results available: The system informs the Experimenter that no results are available for the requested experiment.
* A2 — Results cannot be displayed completely: The system displays the available information and identifies missing data.
* E1 — Storage failure: The system reports that the results could not be saved.
* E2 — Stored results unavailable: If a previously saved result cannot be accessed, the system reports the issue without inventing or substituting results.

UC-08 — Compare Simulation and Real Execution

Brief description

The Experimenter compares the reference behavior obtained through simulation with the behavior observed during a corresponding Linux execution.

Actor(s)

* Experimenter.

Context

The comparison aims to identify differences between expected scheduling behavior and real execution under specific system conditions.

Input data and preconditions

* A simulation result.
* A corresponding Linux execution result.
* Sufficient timing information to perform the requested comparison.

Output data and postconditions

* A comparison of the available timing results.
* Identified differences between simulated and observed behavior.
* Comparison results available for further analysis.

Main scenario

1. The Experimenter selects a simulation result.
2. The Experimenter selects the corresponding Linux execution result.
3. The system checks that the results can be compared.
4. The system compares the available timing information.
5. The system presents the differences between simulated and observed behavior.
6. The Experimenter can consult the comparison results for further analysis.

Variants and error cases

* A1 — Multiple executions: The Experimenter selects different executions of the same scenario to examine variability under different conditions.
* A2 — Incomplete comparison data: The system compares only the available compatible measurements and identifies any limitations.
* E1 — Incompatible scenarios: If the task sets or configurations do not correspond sufficiently, the system warns the Experimenter that the comparison may be invalid.
* E2 — Missing results: If either the simulation or the real execution result is unavailable, the system cannot complete the comparison and reports the missing input.

UC-09 — Analyze Timing Deviations and Missed Deadlines

Brief description

The Experimenter analyzes the differences between expected and observed timing behavior, including response-time variability and missed deadlines.

Actor(s)

* Experimenter.

Context

This use case supports the study of the conditions under which real-time tasks fail to meet their temporal constraints.

Input data and preconditions

* Available simulation and/or execution results.
* Timing measurements and deadline information sufficient for the intended analysis.
* A comparison result, when the analysis concerns differences between simulation and execution.

Output data and postconditions

* An analysis of observed timing deviations.
* Identification of missed deadlines where the data supports this conclusion.
* Results and observations that can be included in the project experiment report.

Main scenario

1. The Experimenter selects the results to analyze.
2. The system presents the relevant timing measurements.
3. The Experimenter examines response times and their variability.
4. The system presents available information about missed deadlines and differences between expected and observed behavior.
5. The Experimenter identifies patterns or conditions associated with the observed deviations.
6. The Experimenter records the conclusions for the experiment report.

Variants and error cases

* A1 — Analyze a single execution: The Experimenter analyzes one execution without comparing it with a simulation.
* A2 — Compare different load conditions: The Experimenter examines results from multiple runs to study the influence of system load.
* A3 — Compare Linux configurations: When corresponding results are available, the Experimenter examines differences between standard Linux and PREEMPT_RT.
* E1 — Insufficient measurements: The system indicates that the available data is insufficient to support the requested analysis.
* E2 — No missed deadlines observed: The analysis reports that no missed deadlines were observed in the available measurements; this does not guarantee that future executions will always meet their deadlines.

4. Notes and Scope

* Primary actor: The Experimenter performs all user-facing actions.
* Scheduling policies: EDF and RM are explicitly mentioned in the project specification. Other policies are outside the current scope unless added later.
* Load generation: stress-ng is a possible tool for generating CPU, memory, and input/output load.
* Instrumentation: ftrace and perf may complement measurements collected by the C++ application.
* Linux configurations: A comparison between standard Linux and PREEMPT_RT is a possible experiment, not an unconditional requirement.
* Reproducibility: Experiment configurations and results should be recorded to support repeatable experiments.
* Implementation choices: The exact user interface, storage format, validation rules, and error-handling mechanisms remain implementation decisions.