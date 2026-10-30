# PFE — Real-Time Scheduling and Performance Analysis under Linux

## Introduction

In some computing applications, tasks must not only produce a correct result but also meet timing constraints. Their behavior can be studied theoretically or through simulation, but execution on a real machine introduces other factors, such as CPU load, memory usage, I/O, or operating system activity.

The goal of this project is to develop an experimental environment that makes it possible to simulate, and then actually run under Linux, sets of tasks subject to timing constraints, in order to study the gaps between their expected behavior and the behavior observed under different execution conditions.

## I – Principle

The project is based on the definition of task sets characterized in particular by their period, execution time, and deadline.

A first part will simulate their scheduling using policies such as Earliest Deadline First (EDF) and Rate Monotonic (RM), in order to obtain a reference behavior.

The same scenarios will then be reproduced under Linux to measure their behavior during real execution. The objective will be, in particular, to observe response times, their variability, and any missed deadlines, and then to study under which conditions these phenomena appear.

A simplified application scenario of periodic data acquisition and processing, representing several (simulated) sensors, will serve as a case study. It will provide tasks with different frequencies and processing loads without requiring any specific hardware.

## II – Experimentation under Linux

Experiments will be carried out under different load conditions in order to study their influence on the timing behavior of the tasks. CPU, memory, and I/O stress can notably be generated with `stress-ng`.

The measurements made by the C++ application can be complemented by Linux instrumentation tools such as `ftrace` and `perf`, in particular to observe events related to scheduling and preemption.

A comparison between execution under standard Linux and a `PREEMPT_RT` configuration may also be carried out to study the influence of the system configuration on the results.

## III – Expected Deliverable

The main deliverable will be an experimental environment developed in C++ under Linux that makes it possible to:

- define and configure sets of tasks subject to timing constraints;
- simulate their scheduling under different policies, notably EDF and RM;
- run equivalent scenarios under Linux and collect the associated timing measurements;
- reproduce the experiments under different load conditions;
- record and compare the results in order to identify the gaps between expected and observed behavior.

The project must also provide a set of reproducible experimental scenarios, the results of the experiments carried out, and an analysis of the main phenomena observed. The source code and its documentation will be delivered, and a demonstration of the environment and of an experimental scenario will be presented during the defense.