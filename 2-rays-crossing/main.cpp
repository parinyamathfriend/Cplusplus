#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

// Function to optimize standard I/O operations for speed
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// Logic for processing a single testcase
void solve() {
    // 1. Read how many numbers to expect
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    cout << "Enter " << n << " numbers separated by spaces: ";
    
    // 2. Create the vector to hold exactly 'n' elements
    vector<long long> numbers(n);
    
    // 3. Loop to fill the vector from terminal input
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // 4. Print the vector back out to prove we captured it
    cout << "\nYou entered the following vector:\n[ ";
    for (int i = 0; i < n; ++i) {
        cout << numbers[i] << " ";
    }
    cout << "]\n\n";
}

int main() {
    // 1. Setup fast input/output
    fast_io();

    // 2. Handle multiple test cases (many competitions use 't' test cases)
    int t = 1;
    
    // Uncomment the next line if the problem statement says the first input is the number of test cases:
    // cin >> t; 

    while (t--) {
        solve();
    }

    return 0;
}
