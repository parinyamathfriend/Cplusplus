#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
vector<int> ray_member(2);
vector<int> ray_1;
vector<int> ray_2;

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

void get_input() {

  for (int i = 0; i < 2; i++) {
    cin >> ray_member[i];
  }
  ray_1.resize(ray_member[0]);
  ray_2.resize(ray_member[1]);
  for (int i = 0; i < ray_member[0]; i++) {
    cin >> ray_1[i];
  }
  for (int i = 0; i < ray_member[1]; i++) {
    cin >> ray_2[i];
  }
  for (int i = 0; i < ray_member[0]; i++) {
    cout << ray_1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < ray_member[1]; i++) {
    cout << ray_2[i] << " ";
  }
  cout << endl;
}

int main() {
  // 1. Setup fast input/output
  fast_io();

  get_input();

  return 0;
}
