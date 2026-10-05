# Operating Systems — Dynamic Memory Allocation

Author: Margarita Harutyunyan

This homework demonstrates dynamic memory allocation in C using
malloc(), calloc(), realloc(), and free().

Tasks 1–5 are required. Tasks 6–7 are optional and are also implemented.

## Source Files

| File | Description |
| --- | --- |
| task1.c | Allocates an integer array and calculates its sum |
| task2.c | Creates a zero-initialized array and calculates its average |
| task3.c | Shrinks an array from 10 integers to 5 |
| task4.c | Grows an array of string pointers from 3 entries to 5 |
| task5.c | Finds the highest and lowest student grades |
| task6.c | Implements my_realloc() using malloc(), memcpy(), and free() |
| task7.c | Implements aligned_malloc() and aligned_free() |

## Environment

The programs were compiled using GCC on the Ubuntu class server.

Compilation uses the C11 standard and enables compiler warnings.

## Compilation

```bash
gcc -Wall -Wextra -std=c11 task1.c -o task1
gcc -Wall -Wextra -std=c11 task2.c -o task2
gcc -Wall -Wextra -std=c11 task3.c -o task3
gcc -Wall -Wextra -std=c11 task4.c -o task4
gcc -Wall -Wextra -std=c11 task5.c -o task5
gcc -Wall -Wextra -std=c11 task6.c -o task6
gcc -Wall -Wextra -std=c11 task7.c -o task7
```

## Execution and Example Results

### Task 1 — Integer Array Sum

```bash
./task1
```

Example input:

```text
5
1 2 3 4 5
```

Expected result:

```text
Sum of the array: 15
```

### Task 2 — Initialized Array and Average

```bash
./task2
```

Example input:

```text
4
5 10 15 20
```

Expected output includes:

```text
Array after calloc: 0 0 0 0
Updated array: 5 10 15 20
Average of the array: 12.50
```

### Task 3 — Shrinking an Array

```bash
./task3
```

Example input:

```text
1 2 3 4 5 6 7 8 9 10
```

Expected result:

```text
Array after resizing: 1 2 3 4 5
```

### Task 4 — Dynamic Strings

```bash
./task4
```

Enter the first three strings:

```text
Hello World C
```

Then enter two additional strings:

```text
Programming Memory
```

Expected output includes:

```text
First 3 strings: Hello World C
All strings: Hello World C Programming Memory
```

Each string must be a single word of at most 50 characters.
Spaces within a string are not supported.
A longer word can leave extra characters for the next input read.

### Task 5 — Student Grades

```bash
./task5
```

Example input:

```text
5
90 85 70 60 95
```

Expected result:

```text
Highest grade: 95
Lowest grade: 60
```

### Task 6 — Custom realloc

```bash
./task6
```

No input is required.

Expected result:

```text
Original array: 10 20 30
Array after growing: 10 20 30 40 50
Array after shrinking: 10 20
```

my_realloc() receives the old and new allocation sizes in bytes.
It copies the smaller size and frees the old block after successful
allocation. Allocation failure preserves the old block.
A zero new size frees the old block and returns NULL.

### Task 7 — Aligned Allocation

```bash
./task7
```

No input is required.

Expected output includes:

```text
Requested alignment: 32 bytes
Memory address: 0x...
Address remainder: 0
Array: 10 20 30 40 50
```

The memory address varies between runs.
A remainder of zero confirms 32-byte alignment.

The alignment must be a nonzero power of two and appropriate
for the data being stored. Use aligned_free() to release memory
returned by aligned_malloc().

## Memory Management

- Allocation results are checked against NULL.
- Input failures release memory already allocated.
- Temporary pointers preserve the original allocations if resizing fails.
- Task 4 frees each string before freeing the pointer array.
- All owned allocations are released on normal completion.

## Submission Materials

The submission includes the C source files, output screenshots,
and a report explaining the implementations.

## Repository

https://github.com/Margarita220103/os-memory-allocation
