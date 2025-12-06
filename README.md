# Tower of Hanoi - Iterative vs Recursive

## About This Project

This repository contains implementations of the Tower of Hanoi puzzle that execute the solution and print each move to the console. Both iterative and recursive approaches are included.

**Note:** For a UI-based visualization with move animations (faster and capable of handling more disks without printing), check out the [Hanoi Visualizer](https://github.com/lai0xn/hanoi) repository.

## Project Structure

```
toh-iterative-vs-recursion/
├── iterative/
│   ├── hanoi_results.csv
│   ├── hanoi.exe
│   └── main.cpp
├── recursive/
│   ├── hanoi_recursive_results.csv
│   ├── hanoi.exe
│   ├── hanoi.cpp
│   ├── hanoi.h
│   └── main.cpp
└── README.md
```

## Features

- **Iterative Implementation**: Solves the Tower of Hanoi puzzle using an iterative approach
- **Recursive Implementation**: Solves the puzzle using the classic recursive algorithm
- **Move Printing**: Each move is printed to the console for educational purposes
- **CSV Results**: Solution steps are saved to CSV files for analysis

## Running the Programs

### Iterative Version

```bash
cd iterative
./hanoi.exe
```

### Recursive Version

```bash
cd recursive
./hanoi.exe
```

## Comparison

Both implementations solve the same problem but demonstrate different algorithmic approaches:

- **Recursive**: More intuitive and elegant, directly follows the mathematical definition
- **Iterative**: Uses a loop-based approach, avoids function call overhead

## Performance Note

Since this implementation prints every move to the console, it's optimized for educational purposes and smaller numbers of disks. For larger disk counts and better performance, use the [UI version](https://github.com/lai0xn/hanoi) which visualizes moves without printing them.
