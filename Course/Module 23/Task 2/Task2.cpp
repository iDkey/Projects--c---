#include <iostream>

#define macro_1 more(train)
#define macro_2 less(train)
#define macro_3 filling(train, summ)
#define summ_considering(count, summ) ((summ) += (count))

void less(int (&train)[10])
{
    for(int i = 0 ; i < 10; ++i)
        (train[i] < 20 ? std::cout <<  "The " << i + 1 << " carriage has less than 20 passengers" << std::endl : std::cout << "");
}
void more(int (&train)[10])
{
    for(int i = 0 ; i < 10; ++i)
        (train[i] > 20 ? std::cout <<  "The " << i + 1 << " carriage has more than 20 passengers" << std::endl : std::cout << "");
}

void filling(int (&train)[10], int& summ)
{
    for(int i = 0; i < 10; ++i)
    {
        std::cout << i + 1 << " train car:" << std::endl;
        std::cin >> train[i];
        summ_considering(train[i], summ);
    }

}

int main()
{
    int train[10];
    int summ = 0;
    std::cout << "Input count in train:" << std::endl;
    macro_3;


    macro_1;
    macro_2;

    std::cout << summ << std::endl;
}

