#include <iostream>

#define less(count_passengers) (count_passengers < 20 ?  true : false)
#define more(count_passengers, num_tc) (count_passengers > 20 ?  std::cout <<  "The " << num_tc << " carriage has more than 20 passengers" << std::endl \
    : std::cout << "")

int main()
{
    int train[10];
    std::cout << "Input count in train:" << std::endl;
    std::cout << "1 train car:" << std::endl;
    std::cin >> train[0];
    std::cout << "2 train car:" << std::endl;
    std::cin >> train[1];
    std::cout << "3 train car:" << std::endl;
    std::cin >> train[2];
    std::cout << "4 train car:" << std::endl;
    std::cin >> train[3];
    std::cout << "5 train car:" << std::endl;
    std::cin >> train[4];
    std::cout << "6 train car:" << std::endl;
    std::cin >> train[5];
    std::cout << "7 train car:" << std::endl;
    std::cin >> train[6];
    std::cout << "8 train car:" << std::endl;
    std::cin >> train[7];
    std::cout << "9 train car:" << std::endl;
    std::cin >> train[8];
    std::cout << "10 train car:" << std::endl;
    std::cin >> train[9];
    /*if(more(train[0]))
        std::cout << "The first carriage has more than 20 passengers" << std::endl;
    if(more(train[1]))
        std::cout << "The second carriage has more than 20 passengers" << std::endl;
    if(more(train[2]))
        std::cout << "The third carriage has more than 20 passengers" << std::endl;
    if(more(train[3]))
        std::cout << "The fourth carriage has more than 20 passengers" << std::endl;
    if(more(train[4]))
        std::cout << "The fifth carriage has more than 20 passengers" << std::endl;
    if(more(train[5]))
        std::cout << "The sixth carriage has more than 20 passengers" << std::endl;
    if(more(train[6]))
        std::cout << "The seventh carriage has more than 20 passengers" << std::endl;
    if(more(train[7]))
        std::cout << "The eighth carriage has more than 20 passengers" << std::endl;
    if(more(train[8]))
        std::cout << "The ninth carriage has more than 20 passengers" << std::endl;
    if(more(train[9]))
        std::cout << "The tenth carriage has more than 20 passengers" << std::endl;

    if(more(train[0]))
        std::cout << "The first carriage has more than 20 passengers" << std::endl;
    if(more(train[1]))
        std::cout << "The second carriage has more than 20 passengers" << std::endl;
    if(more(train[2]))
        std::cout << "The third carriage has more than 20 passengers" << std::endl;
    if(more(train[3]))
        std::cout << "The fourth carriage has more than 20 passengers" << std::endl;
    if(more(train[4]))
        std::cout << "The fifth carriage has more than 20 passengers" << std::endl;
    if(more(train[5]))
        std::cout << "The sixth carriage has more than 20 passengers" << std::endl;
    if(more(train[6]))
        std::cout << "The seventh carriage has more than 20 passengers" << std::endl;
    if(more(train[7]))
        std::cout << "The eighth carriage has more than 20 passengers" << std::endl;
    if(more(train[8]))
        std::cout << "The ninth carriage has more than 20 passengers" << std::endl;
    if(more(train[9]))
        std::cout << "The tenth carriage has more than 20 passengers" << std::endl;*/
    more(train[0], 1);
    more(train[1], 2);
    more(train[2], 3);
    more(train[3], 4);
    more(train[4], 5);
    more(train[5], 6);
    more(train[6], 7);
    more(train[7], 8);
    more(train[8], 9);
    more(train[9], 10);
}