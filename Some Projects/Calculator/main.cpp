#include <iostream>
#include <cmath>
#include <string>

char oper = '0';

class Calc
{
private:

    int a = INT_MIN;
    int b = INT_MIN;
    int result;

public:

    template <typename T>
    void setA(T& num)
    {
        if(num > 47 and num < 58)
            a = int(num - '0');
    }
    template <typename T>
    void setB(T& num1)
    {
        if(num1 > 47 and num1 < 58)
            b = int(num1 - '0');
    }

    int getA()
    {
        return a;
    }

    int getB()
    {
        return b;
    }

    template <typename T>
    T setResult()
    {
        if(oper == '+')
            result = a + b;
        if(oper == '-')
            result = a - b;
        if(oper == '*')
            result = a * b;
        if(oper == '/')
            result = a / b;
    }

    int getResult()
    {
        return result;
    }

    void setOper(char op)
    {
        if(op == 43 or op == 45)
            oper = op;
    }
};

int main() {
    Calc *plus = new Calc();

    char num = '1';
    char num1 = '2';

    plus->setA(num);
    plus->setB(num1);
    plus->setOper('+');

    //std::cout << plus->getA() << std::endl;
    //std::cout << plus->getB() << std::endl;

    plus->setResult<int>();
    std::cout << plus->getA() << " + " << plus->getB() << " = " << plus->getResult() << std::endl;

    oper = '0';
    delete plus;

    Calc *minus = new Calc();

    minus->setA(num);
    plus->setB(num1);

    //std::cout << plus->getA() << std::endl;
    //std::cout << plus->getB() << std::endl;

    plus->setOper('-');

    minus->setResult<int>();
    std::cout << minus->getA() << " + " << minus->getB() << " = " << minus->getResult() << std::endl;

    delete minus;
}
