#include <iostream>

class B 
{
  public:
    virtual void f() {std::cout << "B::f" << "\n";}
};

class C : public B
{
  public:
    virtual void f() override final {std::cout << "C::f" << "\n";}
};

class D : public C
{
  public:
    virtual void f() override {std::cout << "D::f" << "\n";}
};

int main()
{

}

