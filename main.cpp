#include <iostream>
#include <vector>
#include "hw5.h"


void print(std::vector<std::string> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> v = {"apples", "cars", "testingisnotfun", "here", "aaasdfdasdaass", "aaaaaaaaaples"};
  MergeSort(v);
  print(v);
}