#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
struct RayProperties {
  int start_point;
  int end_point;
  int direction; // 0 is down, 1 is up
};
class RayObject {
private:
  // We can store our ray data inside the class.
  // Here we use a vector of our structs.
  vector<RayProperties> rays;
  vector<int> ray_data;

public:
  void SetRayData(vector<int> input_data) { ray_data = input_data; }

  // Method to get a ray by its index
  // This returns the entire struct containing start, end, and direction
  RayProperties get_ray(int index) {
    // Add a safety check to avoid segmentation faults!
    if (index < 0 || index >= rays.size() - 1) {
      cout << "Error: Index out of bounds!" << endl;
      // Return some default/empty ray if out of bounds
      return {0, 0, 0};
    } else {
      RayProperties temp{0, 0, 0};
      if (index == 0) {
        temp.start_point = 0;
        temp.end_point = ray_data[index];
        temp.direction = index % 2;
      } else {
        temp.start_point = ray_data[index - 1];
        temp.end_point = ray_data[index];
        temp.direction = index % 2;
      }
      cout << "Ray " << index << " -> ";
      cout << "start_point " << temp.start_point << " end_point "
           << temp.end_point;
      (temp.direction % 2 == 0) ? cout << " down" : cout << " up";
      cout << endl;
      return temp;
    }
  }
  int countRayElement() { return ray_data.size() - 1; }

  // Method to print info for debugging
  void print_ray(int index) {
    RayProperties r = get_ray(index);
    cout << "Ray " << index << " -> "
         << "Start: " << r.start_point << " | End: " << r.end_point
         << " | Dir: " << r.direction << endl;
  }
};

vector<int> ray_member(2);
vector<int> ray_1;
vector<int> ray_2;
RayObject ray1_object;
RayObject ray2_object;

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
  ray1_object.SetRayData(ray_1);
  ray2_object.SetRayData(ray_2);
}

// 2. Create the class to manage your rays

int main() {
  // 1. Setup fast input/output
  fast_io();

  get_input();
  // ray1_object is main
  // ray2_object is for_count_crossing_poin

  int current_ray_index = 0;
  for (int i = 0; i <= ray2_object.countRayElement(); i++) {
    cout << "current_ray_index " << current_ray_index << endl;
    ray2_object.get_ray(current_ray_index);
    current_ray_index++;
  }
  return 0;
}
