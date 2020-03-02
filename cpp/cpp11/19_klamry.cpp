#include <iostream>
#include <vector> 
#include <map>

int main() 
{
  int a = 0;
  int b (1);
  std::pair<int,int> {2, 3};

  int c = {0};
  int d {0};
  std::vector<int> e {7}; // ??
  std::vector<int> f {0,1,2,3,4};
  std::map<int, std::string> g{
    {1, "one"}, {2, "two"}, {3, "three"}
  };

  std::vector<int> h {e};
  std::vector<int> k {std::move(e)};
}



