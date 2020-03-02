#include <iostream>
#include <map>

int main()
{
  std::map<int, std::string> map;
  map[1] = "jeden";
  map[11] = "jedenaście";

  for(const auto& para : map) 
  {
    std::cout << para.second << "\n";
    for (auto c : para.second)
      if (c == 'e')
        std::cout << "e\n";
  }

  int tab[] {1,2,3,4,5};
  for(int & j : tab) 
  {
    j = j*j;
  }
}


