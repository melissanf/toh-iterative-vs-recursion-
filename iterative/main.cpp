#include <iostream>
#include <stack>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace std::chrono;

// move structure
struct Move
{
    char from; // Source
    char to;   // Destination
};

// Ctoh class
class TowerOfHanoi
{
private:
    int numDisks;
    long long moveCount;

public:
    // Const
    TowerOfHanoi(int n) : numDisks(n), moveCount(0) {}

    // fun printing move
    void printMove(int disk, char from, char to)
    {
        moveCount++;
        /*
            comment line 34 to gain some time
        */
        cout << "Move disk " << disk << " from " << from << " to " << to << endl;
    }

    // total moves
    long long getMoveCount() const
    {
        return moveCount;
    }

    // Iterative solution for Tower of Hanoi
    void solveIterative(char source, char auxiliary, char destination)
    {
        moveCount = 0;

        // total moves  2^n - 1
        long long totalMoves = (1LL << numDisks) - 1;
        stack<int> A, B, C;
        stack<int> *pegs[3];
        char pegNames[3] = {source, auxiliary, destination};

        pegs[0] = &A;
        pegs[1] = &B;
        pegs[2] = &C;

        // Pushing all disks A
        for (int i = numDisks; i >= 1; i--)
        {
            A.push(i);
        }

        // moves directions
        int sourcePeg, destPeg;
        // For even number of disks and odd number of disks,
        if (numDisks % 2 == 0)
        {
            // Even: A->B, A->C, B->C pattern
            sourcePeg = 0; // A
            destPeg = 1;   // B
        }
        else
        {
            // Odd: A->C, A->B, B->C pattern
            sourcePeg = 0; // A
            destPeg = 2;   // C
        }

        // iterative execytion
        for (long long move = 1; move <= totalMoves; move++)
        {
            if (move % 3 == 1)
            {
                //  source and destination
                moveDisk(pegs[sourcePeg], pegs[destPeg],
                         pegNames[sourcePeg], pegNames[destPeg]);
            }
            else if (move % 3 == 2)
            {
                // source and auxiliary
                int auxPeg = 3 - sourcePeg - destPeg; // The remaining peg
                moveDisk(pegs[sourcePeg], pegs[auxPeg],
                         pegNames[sourcePeg], pegNames[auxPeg]);
            }
            else
            {
                // auxiliary and destination
                int auxPeg = 3 - sourcePeg - destPeg;
                moveDisk(pegs[auxPeg], pegs[destPeg],
                         pegNames[auxPeg], pegNames[destPeg]);
            }
        }
    }

    // function to move disk between two pegs
    void moveDisk(stack<int> *from, stack<int> *to, char fromName, char toName)
    {
        // Get top disk from each peg
        int fromTop = from->empty() ? INT_MAX : from->top();
        int toTop = to->empty() ? INT_MAX : to->top();

        // Move the smaller disk to the peg with larger disk
        if (fromTop < toTop)
        {
            // Move from from to to
            to->push(fromTop);
            from->pop();
            printMove(fromTop, fromName, toName);
        }
        else
        {
            // Move from to to from
            from->push(toTop);
            to->pop();
            printMove(toTop, toName, fromName);
        }
    }
};

// Function to run exp and measure execution time
void runExperiment(int n)
{
    cout << "\n========================================" << endl;
    cout << "Testing with n = " << n << " disks" << endl;
    cout << "========================================" << endl;

    TowerOfHanoi hanoi(n);

    auto start = high_resolution_clock::now();

    hanoi.solveIterative('A', 'B', 'C');

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

//  display results table header
void printTableHeader()
{
    cout << "\n"
         << string(70, '=') << endl;
    cout << setw(10) << "n" << setw(25) << "Number of Moves" << setw(30) << "Execution Time (sec)" << endl;
    cout << string(70, '=') << endl;
}

// print a single table row
void printTableRow(int n, long long moves, double time)
{
    cout << setw(10) << n
         << setw(25) << moves
         << setw(30) << fixed << setprecision(6) << time << endl;
}

// print table footer
void printTableFooter()
{
    cout << string(70, '=') << endl;
}

// run comprehensive experiments
void runComprehensiveExperiments()
{
    cout << "\n***** TOWER OF HANOI - ITERATIVE IMPLEMENTATION *****\n"
         << endl;

    // csv for writing
    ofstream csvFile("hanoi_results.csv");
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
        hanoi.solveIterative('A', 'B', 'C');
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

    cout << "\n Theoretical moves = 2^n - 1" << endl;
    cout << "For n >= 22, execution time may become very long more than 1 hour" << endl;
    cout << "\n Results saved to 'hanoi_results.csv'" << endl;
}

int main()
{

    runComprehensiveExperiments();

    /*
      Uncomment the line below
     to Run detailed experiment for a specific n

    */
    // runExperiment(10);

    return 0;
}