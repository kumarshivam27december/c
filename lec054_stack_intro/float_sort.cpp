#include <iostream>
#include <iomanip>
#include <algorithm>

bool compareFloats(float a, float b) {
  return b > a;  // Compare in descending order
}

int main() {
  float arr[] = {3.7, 1.2, 5.6, 2.3, 4.1};
  int size = sizeof(arr) / sizeof(arr[0]);

  std::sort(arr, arr + size, compareFloats);

  std::cout << "Sorted array in descending order: ";
  for (int i = 0; i < size; i++) {
    std::cout<<std::fixed <<std::setprecision(2)<< arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
