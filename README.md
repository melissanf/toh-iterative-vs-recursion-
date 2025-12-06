# Tower of Hanoi - Iterative Implementation

## Overview

This project implements an **iterative solution** to the classic Tower of Hanoi puzzle as part of the Advanced Algorithms and Complexity course. The program measures execution time for varying numbers of disks to analyze the algorithm's time complexity experimentally.

## Problem Description

The Tower of Hanoi is a mathematical puzzle consisting of three pegs and n disks of different sizes. The objective is to move all disks from the source peg (A) to the destination peg (C) using an auxiliary peg (B), following these rules:

- Only one disk can be moved at a time
- A larger disk cannot be placed on top of a smaller disk
- All disks start on peg A in decreasing order of size

## Implementation Details

This project implements **two versions** of the Tower of Hanoi solution:

### 1. Iterative Algorithm

The iterative approach solves the Tower of Hanoi puzzle without recursion, avoiding the recursive method's function call overhead.

**Key Algorithm Features:**

- Uses three stacks to represent the three pegs (A, B, C)
- Total moves required: `2^n - 1`
- Movement pattern depends on whether n is even or odd:
  - **Odd n**: Follows A→C, A→B, B→C pattern
  - **Even n**: Follows A→B, A→C, B→C pattern

### 2. Recursive Algorithm

[TO BE ADDED]

The recursive approach uses the divide-and-conquer strategy to solve the puzzle.

**Key Algorithm Features:**

- [Description to be added]
- [Recursive formula to be added]
- [Base case and recursive case to be added]

### Code Structure

#### Classes and Functions

**`TowerOfHanoi` Class**

- **Constructor**: `TowerOfHanoi(int n)` - Initializes the puzzle with n disks
- **`solveIterative()`** - Iterative algorithm implementation
- **`solveRecursive()`** - [TO BE ADDED] Recursive algorithm implementation
- **`moveDisk()`** - Handles legal disk movements between pegs (iterative version)
- **`printMove()`** - Outputs each move (can be commented out for performance)
- **`getMoveCount()`** - Returns total number of moves executed

**Main Functions**

- **`runExperiment(int n)`** - Runs a single experiment for n disks
- **`runComprehensiveExperiments()`** - Tests multiple values of n and generates results
- **`printTableHeader/Row/Footer()`** - Formats console output

## Compilation and Execution

### Requirements

- C++ compiler with C++11 support or higher (g++, clang++)
- Standard libraries: `<iostream>`, `<stack>`, `<chrono>`, `<cmath>`, `<iomanip>`, `<fstream>`

### Compilation

```bash
g++ -std=c++11 -o hanoi tower_of_hanoi.cpp
```

Or with optimization:

```bash
g++ -std=c++11 -O2 -o hanoi tower_of_hanoi.cpp
```

### Execution

```bash
./hanoi
```

## Features

### 1. Comprehensive Testing

The program automatically tests multiple values of n: **5, 10, 15, 20, 21, 22**

### 2. Performance Measurement

- Uses `std::chrono::high_resolution_clock` for precise timing
- Measures execution time in microseconds, displays in seconds
- Tracks actual number of moves and compares with theoretical value

### 3. Results Export

- Generates `hanoi_results.csv` file containing:
  - Number of disks (n)
  - Number of moves executed
  - Execution time (seconds)
  - Theoretical number of moves (2^n - 1)

### 4. Console Output

Displays formatted table with:

- Number of disks
- Total moves
- Execution time

### 5. Performance Optimization

Line 34 (`cout << "Move disk..."`) can be commented out to significantly improve performance for large n values, as printing each move is time-consuming.

## Output Format

### Console Output Example

```
***** TOWER OF HANOI - ITERATIVE IMPLEMENTATION *****

======================================================================
         n          Number of Moves         Execution Time (sec)
======================================================================
         5                       31                      0.028896
        10                     1023                      0.880783
        15                    32767                      26.210834
        20                  1048575                      856.011616
        21                  2097151                      1542.019813
        22                  4194303                      3649.670882
======================================================================
```

### CSV Output Format

```csv
n,Number_of_Moves,Execution_Time_seconds,Theoretical_Moves
5,31,0.000123,31
10,1023,0.001456,1023
...
```

## Experimental Results

### Time Complexity Analysis

Both algorithms have **O(2^n)** time complexity:

- Each increment of n approximately doubles the execution time
- Number of moves = 2^n - 1

### Comparative Analysis

#### Iterative vs Recursive Performance

[TO BE ADDED - After implementing both versions]

| n | Iterative Time (s) | Recursive Time (s) | Difference |
|---|--------------------|--------------------|------------|
| 5 | [TBA] | [TBA] | [TBA] |
| 10 | [TBA] | [TBA] | [TBA] |
| 15 | [TBA] | [TBA] | [TBA] |
| 20 | [TBA] | [TBA] | [TBA] |
| 21 | [TBA] | [TBA] | [TBA] |
| 22 | [TBA] | [TBA] | [TBA] |

**Expected Observations:**

- Iterative version should be slightly faster due to no function call overhead
- Recursive version may hit stack overflow for very large n
- Both produce identical number of moves (2^n - 1)

### Practical Limitations

Based on testing:

- **n ≤ 20**: Executes in seconds (practical)
- **n = 21**: Takes several seconds
- **n = 22**: Takes minutes to hours depending on hardware
- **n ≥ 23**: Becomes impractical (execution time exceeds 1 hour)

### Hardware Dependency

The exact value where the program becomes impractical depends on:

- CPU speed and architecture
- Available memory
- Whether move printing is enabled (line 34)

## Customization

### Testing Specific Values

To test a specific value of n, modify the `testValues` array in `runComprehensiveExperiments()`:

```cpp
int testValues[] = {5, 10, 15, 20, 21, 22, 23}; // Add or remove values
```

### Single Experiment Mode

Uncomment the line in `main()` to run a detailed experiment:

```cpp
runExperiment(10); // Test with n=10 disks
```

### Disable Move Printing

Comment out line 34 for better performance:

```cpp
// cout << "Move disk " << disk << " from " << from << " to " << to << endl;
```

## Theoretical Background

### Number of Moves Formula

```
Total Moves = 2^n - 1
```

Examples:

- n=5: 31 moves
- n=10: 1,023 moves
- n=20: 1,048,575 moves
- n=30: 1,073,741,823 moves

### Why Compare Iterative and Recursive?

**Iterative Advantages:**

- No function call overhead
- No risk of stack overflow
- Slightly faster for large n
- More memory efficient

**Iterative Disadvantages:**

- More complex implementation
- Less intuitive than recursive approach

**Recursive Advantages:**

- [TO BE ADDED]
- [Simpler, more elegant code]
- [Directly reflects the problem structure]

**Recursive Disadvantages:**

- [TO BE ADDED]
- [Function call overhead]
- [Stack overflow risk for large n]

## Data Analysis

1. **Linear scale**: Shows exponential growth curve
   - X-axis: n (number of disks)
   - Y-axis: Execution time (seconds)

## Troubleshooting

### Program Hangs

- You may have set n too high (≥23)
- Terminate with Ctrl+C and reduce n value

### CSV File Not Created

- Check write permissions in current directory
- Ensure sufficient disk space

### Compilation Errors

- Verify C++11 support: `g++ --version`
- Check all required headers are available

## License

This project is submitted as part of academic coursework at USTHB.

## References

- Course: Advanced Algorithms and Complexity
- Instructor: Dr. S. KALI ALI
- Institution: University of Science and Technology Houari Boumediene
