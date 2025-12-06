#include <iostream>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace std::chrono;

// Tower of Hanoi Recursive class
class TowerOfHanoi
{
private:
    int numDisks;
    long long moveCount;

public:
    // Constructor
    TowerOfHanoi(int n) : numDisks(n), moveCount(0) {}

    // Function for printing move
    void printMove(int disk, char from, char to)
    {
        moveCount++;
        /*
            Comment line 24 to gain some time for benchmarking
        */
        cout << "Move disk " << disk << " from " << from << " to " << to << endl;
    }

    // Get total moves
    long long getMoveCount() const
    {
        return moveCount;
    }

    // Recursive solution for Tower of Hanoi
    void solveRecursive(int n, char source, char destination, char auxiliary)
    {
        if (n == 0)
            return;

        // Move n-1 disks from source to auxiliary using destination
        solveRecursive(n - 1, source, auxiliary, destination);

        // Move the nth disk from source to destination
        printMove(n, source, destination);

        // Move n-1 disks from auxiliary to destination using source
        solveRecursive(n - 1, auxiliary, destination, source);
    }

    // Wrapper function to start recursive solution
    void solve(char source, char auxiliary, char destination)
    {
        moveCount = 0;
        solveRecursive(numDisks, source, destination, auxiliary);
    }
};

// Function to run experiment and measure execution time
void runExperiment(int n)
{
    cout << "\n========================================" << endl;
    cout << "Testing with n = " << n << " disks" << endl;
    cout << "========================================" << endl;

    TowerOfHanoi hanoi(n);

    auto start = high_resolution_clock::now();

    hanoi.solve('A', 'B', 'C');

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    // Calculate theoretical number of moves
    long long theoreticalMoves = (1LL << n) - 1;

    // Display results
    cout << "Completed!" << endl;
    cout << "Number of moves: " << hanoi.getMoveCount() << endl;
    cout << "Theoretical moves: " << theoreticalMoves << endl;
    cout << "Execution time: " << fixed << setprecision(6)
         << duration.count() / 1000000.0 << " seconds" << endl;
}

// Display results table header
void printTableHeader()
{
    cout << "\n"
         << string(70, '=') << endl;
    cout << setw(10) << "n" << setw(25) << "Number of Moves" << setw(30) << "Execution Time (sec)" << endl;
    cout << string(70, '=') << endl;
}

// Print a single table row
void printTableRow(int n, long long moves, double time)
{
    cout << setw(10) << n
         << setw(25) << moves
         << setw(30) << fixed << setprecision(6) << time << endl;
}

// Print table footer
void printTableFooter()
{
    cout << string(70, '=') << endl;
}

// Run comprehensive experiments
void runComprehensiveExperiments()
{
    cout << "\n***** TOWER OF HANOI - RECURSIVE IMPLEMENTATION *****\n"
         << endl;

    // CSV file for writing
    ofstream csvFile("hanoi_recursive_results.csv");
    if (!csvFile.is_open())
    {
        cerr << "Error: Could not create CSV file!" << endl;
        return;
    }

    // Write CSV header
    csvFile << "n,Number_of_Moves,Execution_Time_seconds,Theoretical_Moves" << endl;

    printTableHeader();

    // Test values for n
    int testValues[] = {5, 10, 15, 20, 21, 22};
    int numTests = sizeof(testValues) / sizeof(testValues[0]);

    for (int i = 0; i < numTests; i++)
    {
        int n = testValues[i];
        TowerOfHanoi hanoi(n);

        auto start = high_resolution_clock::now();
        hanoi.solve('A', 'B', 'C');
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start);
        double timeInSeconds = duration.count() / 1000000.0;
        long long moves = hanoi.getMoveCount();
        long long theoretical = (1LL << n) - 1;

        // Print to console
        printTableRow(n, moves, timeInSeconds);

        // Write to CSV file
        csvFile << n << "," << moves << "," << fixed << setprecision(6)
                << timeInSeconds << "," << theoretical << endl;
    }

    printTableFooter();
    csvFile.close();

    cout << "\nTheoretical moves = 2^n - 1" << endl;
    cout << "For n >= 22, execution time may become very long (more than 1 hour)" << endl;
    cout << "\nResults saved to 'hanoi_recursive_results.csv'" << endl;
}

int main()
{
    runComprehensiveExperiments();

    /*
      Uncomment the line below
      to run detailed experiment for a specific n
    */
    // runExperiment(10);

    return 0;
}