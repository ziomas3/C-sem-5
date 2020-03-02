#include <iostream>
#include <memory>

void f(int* p)
{
  std::cout << *p << std::endl;
}

int main()
{
  std::shared_ptr<int> p1 { new int(10) };
  std::shared_ptr<int> p2 { p1 };

  if(p1)
    f(p1.get());

  (*p2)++;

  if(p2)
    f(p2.get());
}


