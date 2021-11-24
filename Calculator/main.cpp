#include <iostream>

double Calculate (double a,char oper,double b){
    switch(oper)
    {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            if (b==0) {std::cout<<"Error";} 
            else return a/b;
        default:
            return 0.0;
    }
}

int main(){
    double a,b,result;
    char oper;

    while(true){
        std::cin>>a>>oper>>b;
        result=Calculate(a,oper,b);
        std::cout<<result;
    }
    return 0;
}