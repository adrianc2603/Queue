# Queue
## By Adrian Currington

### Description
This queue stores void* elements, allowing an item of any type to be stored by storing a pointer to that item. This queue operates as normal (FIFO - first in, first out) through enqueue and dequeue operations.

### Files Includes
- main.h: Header file for my queue.
- main.c: Implementation code for my queue.
- tester.c: Tester code to test the functionality of each method in main.c.
- main.c.gcov: Shows the coverage of the main.c code when the tester.c file is run.

### Run On Your Machine
I ran the tester code with the following inputs to the command line:
1. gcc tester.c main.c
2. ./a.out
