#include <iostream>

int main(){
    int num;
    std::cin>>num; // считываем размер массива
    int *size = new int[num]; //создаем динамический массив размеров num
    for (int i=0; i<num; i++){
        size[i]=i;
        std::cout<<size[i]<<std::endl; //для перехода на строку без std указывать пространство имен
    }
    delete [] size;// чистим память
    return 0;
}

