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

Работа с файлами:
Библиотека <fstream>
ifstream файл на чтение, ofstream - на запись
std::ios::binary - bin format
file.is_open() проверка, на возможность открытия файл
file.eof() - конец файла

Maps:
Библиотека <map>
hand_book_names.insert(std::pair<type 1, type 2> (variable 1, variable 2));
hand_book_names.insert(std::make_pair<type 1, type 2> (variable 1, variable 2));
std::map<type 1, type 2>::iterator name_iterator;
name_iterator -> first - ключ
name_iterator -> second - значение по ключу
Ключ уникален, при повторении ключа, значение перезаписывается

Время:
Библиотека <ctime>
std::time_t t = std::time(nullptr); время в секундах
std::tm* local = std::localtime(&t); часы
std::asctime(local); полная дата и время
Библиотека <iomanip>
Вывод даты:
std::put_time(local, "%Y") вывод даты (только для формата вывода)
"%Y" - year в виде хххх
"%y" - year в виде хх
"%m" - month
"%d" - day
"%H" - hours
"%M" - minutes
"%S" - seconds
"%I" - для 12 числового отображения часов
"%A" - для вывода дня недели
"%B" - для словесного наименования месяца
Создание и ввод даты:
std::time_t t = std::time(nullptr);
std::tm local = *std::localtime(&t);
std::cin >> std::get_time(&local, "%H:%M")
Разница во времени:
Функция возвращает разницу в секундах
std::time_t a = std::time(nullptr);
std::time_t b = std::time(nullptr);
double d = std::difftime(a, b);
Со структурой std::tm можно манипулировать, например:
local -> tm_sec + 12
Но нужно быть аккуратным, потому что нельзя выходить за границы времени (максимум 59 секб 59 мин и тд)