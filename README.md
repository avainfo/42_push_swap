*This project has been created as part of the 42 curriculum by ando-sou.*

# Push_swap

## Description
Push_swap is a 42 school algorithm project. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a limited set of instructions, with the absolute minimum number of operations possible. It challenges students on algorithm concepts, complexity (Big O), and C programming under strict constraints (Norme).

## Features
- **Efficient Sorting**: Implements a robust **LIS (Longest Increasing Subsequence)** + **Greedy strategy**.
- **Advanced Parsing**: Handles both multi-argument inputs (`./push_swap 1 2 3`) and single string inputs (`./push_swap "1 2 3"`).
- **Coordinate Compression**: Maps arbitrary integers to a simplified rank range `[0, N-1]`.
- **Optimization**: Calculates move costs dynamically to execute the cheapest operations (utilizing `rr` and `rrr` for efficiency).

## Instructions

### Compilation
Use the `Makefile` to compile the project:
```bash
make        # Compiles the executable 'push_swap'
make clean  # Removes object files
make fclean # Removes object files and the executable
make re     # Recompiles everything
```

### Execution
Run the program with a list of integers as arguments:
```bash
./push_swap 4 67 3 87 23
```

It outputs the list of Move instructions to sort numbers.

To verify the result (using a compatible checker):
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Resources & AI Usage

### Resources
- **Algorithms**: Research on Longest Increasing Subsequence (LIS) and Turk Algorithm (conceptually similar to the greedy approach used here).

### AI Usage
AI assistance was used exclusively for documentation purposes:
- Improving clarity and structure of the README.
- Helping formulate concise explanations of the project goals and algorithmic choices.
