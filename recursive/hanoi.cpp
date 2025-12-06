#include "hanoi.h"
#include <fstream>
#include <iostream>

void HanoiSolver::solve(int n, int source, int dest, int aux, bool recordMoves) {
    if (n == 0) return;

    solve(n - 1, source, aux, dest, recordMoves);

    // Only store moves if we are visualizing (recordMoves = true)
    // This prevents memory crash for N > 25 during benchmarking
    if (recordMoves) {
        moveHistory.push_back({source, dest, n});
    }

    solve(n - 1, aux, dest, source, recordMoves);
}

void HanoiSolver::reset() {
    moveHistory.clear();
    lastExecutionTimeMs = 0.0;
}

bool HanoiSolver::saveToCSV(const std::vector<BenchmarkResult>& results, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;

    // CSV Header
    file << "Number of Disks (n),Execution Time (ms)\n";

    // Data rows
    for (const auto& res : results) {
        file << res.n << "," << res.timeMs << "\n";
    }

    file.close();
    return true;
}
