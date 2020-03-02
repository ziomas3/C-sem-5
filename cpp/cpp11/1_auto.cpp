#include <iostream>
#include <list>

int main()
{
  std::list<std::string> lista {"Ala", "Ela", "Olek"};
  for (auto it = lista.begin(); it != lista.end(); ++it)
    std::cout << *it << "\n";
}


