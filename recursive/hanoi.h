#ifndef HANOI_H
#define HANOI_H

#include <vector>
#include <string>
#include <chrono>

struct Move {
    int fromPeg;
    int toPeg;
    int diskSize;
};

struct BenchmarkResult {
    int n;
    double timeMs;
};

class HanoiSolver {
public:
    std::vector<Move> moveHistory;
    double lastExecutionTimeMs;

    // Added 'recordMoves' parameter (default true)
    // Set to false for benchmarking high N values to avoid Out of Memory
    void solve(int n, int source, int dest, int aux, bool recordMoves = true);
    
    void reset();

    // Static helper to save results
    static bool saveToCSV(const std::vector<BenchmarkResult>& results, const std::string& filename);
};

#endif
