#include <iostream>
#include <list>
#include <typeinfo> // z c++ 98

int main()
{
  std::list<std::string> lista {"Ala", "Ela", "Olek"};
  auto it = lista.begin(); 
  std::cout << "1) " << typeid(lista).name() << "\n";
  std::cout << "2) " << typeid(it).name() << "\n";
  std::cout << "3) " << typeid(*it).name() << "\n";
  std::cout << "4) " << typeid('a' + 88).name() << "\n";
} 


