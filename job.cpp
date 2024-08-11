#include <iostream>
#include <algorithm>

using namespace std;

struct Job {
    char id;     // Job Id
    int deadline; // Deadline of job
    int profit;  // Profit if job is completed before or on deadline
};

// Function to sort jobs according to profit in descending order
bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

// Function to find the maximum profit job sequence
void jobSequencing(Job jobs[], int n) {
    // Sort all jobs according to decreasing order of profit
    sort(jobs, jobs + n, comparison);

    int result[n]; // To store the result (sequence of jobs)
    bool slot[n];  // To keep track of free time slots

    // Initialize all slots to be free
    for (int i = 0; i < n; i++)
        slot[i] = false;

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (we start from the last possible slot)
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            // Free slot found
            if (!slot[j]) {
                result[j] = i; // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }

    // Print the result
    cout << "Job sequence for maximum profit: ";
    for (int i = 0; i < n; i++) {
        if (slot[i])
            cout << jobs[result[i]].id << " ";
    }
    cout << endl;
}

int main() {
    Job jobs[] = { {'a', 2, 100}, {'b', 1, 27}, {'c', 2, 15}, {'d', 1, 10} };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}

