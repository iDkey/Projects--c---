#include<iostream> //угадать задуманное случайное число за 7 попыток
#include<cstdlib>
#include <ctime>

int stop=0;//для выхода при отказе

void compare(int a, int b){ //сравнение с числом пользователя
    if (a<b) std::cout<<"u number's larger"<<std::endl;
    if (a>b) std::cout<<"u number's smaller"<<std::endl;
}

int generate () { //генерация числа
    srand(time(0));
    return rand()%100 +1;
}

int check (int a, int b){ //проверка на правильность введенного числа
    if (a==b) return 1;  
       else {compare(a,b); return 0;}
}
char again(){ //играть еще раз или нет
    char d;
    while (d!='y' && d!='n'){
        std::cout<<"r u try again?"<<std::endl;
        std::cin>>d;
        }
    if (d =='n') {std::cout<<"Ty for playing"; stop=1;}
}

char win(){  //случай победы
    std::cout<<"U win!!!"<<std::endl;
    again();
}

char lose(int a){ //случай поражения
    std::cout<<"U Lose!!! It was "<<a<<std::endl;
    again();
}
int main(){
    int a,b,Check=0,i;
    char nt='y';
    while (nt=='y'){ //работает пока не отказано в повторе
        if (stop==1) break;
        a=generate();
        std::cout<<a<<std::endl;
        for(i=1;i<=7;i++){
            std::cout<<"Enter u number: ";
            std::cin>>b;
            Check=check(a,b);
            if (Check==1) { win(); break; }
            if (i==7) nt=lose(a);
            }
    }
    return 0;
}