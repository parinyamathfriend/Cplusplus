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
void print_ray(RayProperties input) {
  cout << "start: " << input.start_point << " end: " << input.end_point
       << " direction: ";
  if (input.direction == 0) {
    cout << "down" << endl;
  } else {
    cout << "up" << endl;
  }
};
class RayObject {
private:
  // We can store our ray data inside the class.
  // Here we use a vector of our structs.
  vector<RayProperties> rays;
  vector<int> ray_data;

public:
  void SetRayData(vector<int> input_data) { ray_data = input_data; }
  int current_query_slot = 0;
  RayProperties get_current_query_ray() { return get_ray(current_query_slot); }
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
      return temp;
    }
  }
  // RayProperties get_ray_in_range(int start, int end) {
  //   RayProperties current_selected=get_ray(current_query_slot);
  //   RayProperties temp{0, 0, 0};
  //   return temp;
  // }
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

bool cross_ray_check(RayProperties to_check, RayProperties main_ray) {
  bool cross_ray = false;
  if (to_check.direction == main_ray.direction) {
    // case1:
    if (to_check.start_point < main_ray.start_point &&
        main_ray.end_point < to_check.end_point) {
      cross_ray = true;
    } else if (to_check.start_point > main_ray.start_point &&
               to_check.end_point < main_ray.end_point) {
      cross_ray = true;
    } else if (to_check.end_point == main_ray.end_point) {
      cross_ray = true;
    }
  } else {
    if (to_check.end_point > main_ray.start_point) {
      cross_ray = true;
    }
  }
  return cross_ray;
}
// 2. Create the class to manage your rays

int main() {
  // 1. Setup fast input/output
  fast_io();

  get_input();
  // ray1_object is main
  // ray2_object is for_count_crossing_poin
  cout << endl;
  cout << "Process begins" << endl;
  cout << endl;

  int cross_count = 1; // start at the same poin, also count as crossing

  for (int i = 0; i <= ray2_object.countRayElement(); i++) {
    cout << "loop: " << (i + 1) << endl;
    RayProperties ray_to_check = ray2_object.get_ray(i);
    RayProperties current_main_ray;
    cout << "ray to check: ";
    print_ray(ray_to_check);
    cout << "Here are slot to compare";
    cout << endl;
    do {
      current_main_ray = ray1_object.get_current_query_ray();
      print_ray(current_main_ray);
      if (cross_ray_check(ray_to_check, current_main_ray)) {
        cross_count++;
        cout << "cross_count: " << cross_count << endl;
      }
      if (ray_to_check.end_point >= current_main_ray.end_point) {
        ray1_object.current_query_slot++;
      }
    } while (ray_to_check.end_point > current_main_ray.end_point &&
             ray1_object.current_query_slot <= ray1_object.countRayElement());

    cout << "****************" << endl;
  }
  cout << "total cross_count: " << cross_count << endl;
  return 0;
}
