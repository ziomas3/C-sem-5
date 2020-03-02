#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int arr[] = {1, 2, 3, 4};
  std::for_each(std::begin(arr), std::end(arr), [](int n) {
    std::cout << n << " ";
  });
  std::vector<int> v {-1, -2, -3, -4};
  std::for_each(std::begin(v), std::end(v), [](int n) {
    std::cout << n << " ";
  });
  std::cout << "\n";
}


