# push_swap
## Project Overview
**push_swap** is a sorting algorithm project from 42 School. The goal is to sort a stack of integers using a limited set of operations with the smallest possible number of moves.

## Description
You must write a program that calculates and displays a sequence of instructions to sort a list of integers using two stacks (a and b) and a restricted set of operations. The main focus is algorithm efficiency and minimizing the number of operations.

## Allowed Operations
You can only use the following operations to manipulate the stacks:
* sa – swap the first two elements of stack a
* sb – swap the first two elements of stack b
* ss – sa and sb at the same time
* pa – push the top element from b to a
* pb – push the top element from a to b
* ra – rotate stack a up by 1
* rb – rotate stack b up by 1
* rr – ra and rb at the same time
* rra – reverse rotate stack a
* rrb – reverse rotate stack b
* rrr – rra and rrb at the same time

## Usage
##### 1. Compile the program
```
make
```
##### 2. Run it with a list of integers(it handles quoted numbers also)
```
./push_swap 3 "2" 1 "6" 5 7
```
⚠️✅ It handles both quoted and unquoted numbers.
##### The program will output sequence of operations to sort the given numbers.

## Example
```
$./push_swap 3 2 1
ra
sa
```
## Project Constraints
* Only the allowed operations is used
* No use of standard sorting functions
* Handles errors: non-integer input, duplicates, and overflows


