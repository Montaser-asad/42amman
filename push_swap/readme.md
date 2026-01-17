# This project has been created as part of the 42 curriculum by <masad>

-------------------------------------------------------------------------------------------------------------------------------------------------------------

# push_swap

A sorting algorithm project that sorts data on a stack using a limited set of operations, with the goal of using the smallest number of actions possible.

## Description

**push_swap** is a 42 school project that challenges you to sort a stack of integers in ascending order using two stacks and a specific set of operations. The program must output the smallest list of instructions to sort the input.

### The Challenge

- You have two stacks: **stack A** and **stack B**
- Initially, stack A contains a random list of integers (no duplicates)
- Stack B is empty
- The goal is to sort stack A in ascending order with the minimum number of operations

## Algorithm

- **For 2-5 numbers**: Hardcoded optimal solutions

- **For larger stacks**: [Radix sort]

This implementation uses a Binary Radix Sort algorithm based on indexed positions:
How it Works

Indexing Phase:

First, the input numbers are converted to indices representing their sorted position
For example, if the input is 9 8 7 6 5 4 0 1 2
The indices become 8 7 6 5 4 3 0 1 2 (where 0 is the smallest, 8 is the largest)


Binary Conversion:

Each index is converted to its binary representation
Example: index 5 → 101 in binary


Radix Sort by Bit:

Starting from the least significant bit (rightmost), we sort the stack
If the current bit is 1, the number stays in and get moved to the bottom of stack A
If the current bit is 0, the number is pushed to stack B
After processing all numbers, push everything back from B to A
Repeat this process for each bit position (LSB to MSB)

## Operations

The program can perform the following operations:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack A |
| `sb` | Swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top element of stack B to stack A |
| `pb` | Push the top element of stack A to stack B |
| `ra` | Rotate stack A (shift up all elements by 1) |
| `rb` | Rotate stack B (shift up all elements by 1) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (shift down all elements by 1) |
| `rrb` | Reverse rotate stack B (shift down all elements by 1) |
| `rrr` | `rra` and `rrb` at the same time |

## Instructions

```bash
# Navigate to the project directory
cd push_swap

# Compile the project
make
```

This will create the `push_swap` executable.

## Usage

```bash
# Basic usage
./push_swap 4 67 3 87 23

# Using quotes
./push_swap "4 67 3 87 23"

# Count the number of operations
./push_swap 4 67 3 87 23 | wc -l
```

### Error Handling

The program displays "Error" on the standard error output when:
 - Arguments are not integers
- Arguments exceed integer limits
- There are duplicate numbers

### Resources
- https://www.youtube.com/watch?v=Y95a-8oNqps
- https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
