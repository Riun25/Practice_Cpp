#include <iostream>

class Z
{
public:
    virtual void funcA() { std::cout << "A::funcA()\n"; }
    virtual void funcB() { std::cout << "A::funcB()\n"; }
    virtual void funcC() { std::cout << "A::funcC()\n"; }
};

class A : public Z
{
public:
    virtual void funcA() { std::cout << "A::funcA()\n"; }
};

class B : public Z
{
public:
    virtual void funcB() { std::cout << "B::funcB()\n"; }
};

class C : public A, public B 
{
public:
    void funcA() override { std::cout << "C::funcA()\n"; }
    void funcB() override { std::cout << "C::funcB()\n"; }
private:
    int a = 0;
};

int main() 
{
    C* obj = new C;
    A* pA = obj;
    B* pB = obj;

    pA->funcA();  // C::funcA()
    pB->funcB();  // C::funcB()

    std::cout << "A狼 vptr 林家: " << reinterpret_cast<void**>(obj)[0] << '\n';
    std::cout << "B狼 vptr 林家: " << reinterpret_cast<void**>(obj)[1] << '\n';
    std::cout << "C狼 vptr 林家: " << reinterpret_cast<void**>(obj)[2] << '\n';

    std::cout << sizeof(*obj) << "\n";

    return 0;
}