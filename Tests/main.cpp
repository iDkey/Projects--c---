#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
    void foo() const {cout << "Base::foo" << endl;}
    virtual void bar() const {cout << "Base::bar" << endl;}
};

class Derived: public Base{
public:
    void foo() const {cout << "Derived::food" << endl;}
    virtual void bar() const {cout << "Derived::bar" << endl;}
};

int main()
{
    Base b;
    Derived d;
    Base* pb = &d;
    b.foo();  // Печатает Base::foo
    b.bar();  // Печатает Base::bar
    d.foo();  // Печатает Derived::foo
    d.bar();  // Печатает Derived::bar
    pb->foo();    // Печатает Base::foo, хотя pb указывает на объект Derived, потому что pb имеет тип Base*
    pb->bar();    // Печатает Derived::bar, потому что функция виртуальная и вызывается через сам объект, который знает свой настоящий тип
}