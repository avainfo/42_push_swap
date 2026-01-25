*This project has been created as part of the 42 curriculum by ando-sou.*

# Push_swap

## Description

**Push_swap** is a 42 school algorithm project.
The goal is to sort a stack of integers using **two stacks (`a` and `b`)** and a **restricted set of instructions**, while producing **the smallest possible number of operations**.

The project focuses on:

* Algorithmic reasoning and optimization
* Time and space complexity
* Low-level C programming under strict constraints (42 Norme)

A **bonus program (`checker`)** is also implemented to validate instruction sequences.

---

## Features

### Mandatory part

* **Efficient Sorting Algorithm**
  Uses a **LIS (Longest Increasing Subsequence) + Greedy cost-based strategy** to minimize the number of operations.
* **Advanced Parsing**
  Supports both multiple arguments and single quoted strings:
  `./push_swap 1 2 3`
  `./push_swap "1 2 3"`
* **Robust Validation**

  * Integer overflow handling
  * Duplicate detection
  * Invalid input detection
* **Coordinate Compression**
  Maps values to a normalized index range `[0, N-1]` for faster comparisons.
* **Move Optimization**
  Dynamically computes move costs and merges rotations using `rr` and `rrr`.

### Bonus part

* **Custom Checker Program**
  A `checker` binary capable of:

  * Reading instructions from standard input
  * Executing them on the stacks
  * Validating if stack `a` is sorted and stack `b` is empty
* **Strict Error Handling**
  Detects:

  * Invalid instructions
  * Invalid arguments
  * Overflows
  * Duplicates

---

## Instructions

### Compilation

Use the `Makefile`:

```bash
make        # Compiles push_swap
make bonus  # Compiles checker
make clean  # Removes object files
make fclean # Removes object files and binaries
make re     # Full recompilation
```

---

### Execution

#### push_swap

```bash
./push_swap 4 67 3 87 23
```

Outputs the list of instructions required to sort the stack.

#### checker (bonus)

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

Output:

* `OK` if sorted correctly
* `KO` otherwise

You can also test manually:

```bash
./checker 3 2 1 0
rra
pb
sa
rra
pa
```

---

## Project Constraints

* Written in **C**
* Fully compliant with **42 Norme**
* No global variables
* No memory leaks
* Instructions printed one per line
* No output if no arguments are provided
* On error, prints `Error\n` to stderr

---

## Resources & AI Usage

### Resources

* 42 subject PDF

* Algorithm references:

  * Longest Increasing Subsequence (LIS)
  * Greedy cost-based sorting strategies (Turk-inspired approach)

### AI Usage

AI tools were used **exclusively for documentation purposes**, in accordance with the 42 AI rules:

* Improving clarity and structure of the README
* Helping rephrase explanations of algorithmic choices (because english is hard)

No AI-generated code was used in the implementation.
