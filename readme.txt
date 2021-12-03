Для рандома использовать:
#include <random>
#include <ctime>
...
std::mt19937 gen(static_cast<unsigned int>(time(0)));
std::uniform_int_distribution<> <временное имя>(<левая граница включительно>,<правая граница включительно>);
<имя переменной> = <временное имя>(gen);
Пример:
std::mt19937 gen(static_cast<unsigned int>(time(0)));
std::uniform_int_distribution<> rand_x(1,40);
x = rand_x(gen);