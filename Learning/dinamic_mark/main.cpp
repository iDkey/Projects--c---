#include<iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

int main(){
    int amount,a,b;
    std::cin>>amount;
    std::string **mass = new std::string* [amount]; // объявляется указатель второго порядка float **mass, который ссылается на массив указателей  float* [amount], 
    for (int i = 0; i < amount; i++) {//где размер массива равен amount. После чего в цикле for каждой строке массива, объявленного в строке 2, выделяется память под 2 элементa
        mass[i] = new std::string [2];
    }
    //заполняем
    for (a=0; a<amount; a++){
        for (b=0; b<2; b++){
            std::cin>>mass[a][b];
        }
    }
    //сортируем
    for (a=0; a<amount-1; a++){
        for (b=0; b<2; b++){
            //??????????????????????????????            
        }
    }
    //выводим
    for (a=0; a<amount; a++){
        for (b=0; b<2; b++){
            std::cout<<mass[a][b];
        }
    }
    //удаляем
    for (int i = 0; i < 2; i++) {delete [] mass[i];}

    return 0;
}