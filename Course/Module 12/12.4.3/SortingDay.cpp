#include <iostream>


// Функция "просеивания" через кучу - формирование кучи
void siftDown(float *numbers, int root, int bottom)
{
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done)) 
    {
        if (root * 2 == bottom)    // если мы в последнем ряду,
            maxChild = root * 2;    // запоминаем левый потомок
            // иначе запоминаем больший потомок из двух
        else 
            if (numbers[root * 2] > numbers[root * 2 + 1])
                maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
            // если элемент вершины меньше максимального потомка
            if (numbers[root] < numbers[maxChild]) 
            {
                float temp = numbers[root]; // меняем их местами
                numbers[root] = numbers[maxChild];
                numbers[maxChild] = temp;
                root = maxChild;
            }
            else // иначе
                done = 1; // пирамида сформирована
    }
}

// Функция сортировки на куче
void heapSort(float *numbers, int array_size) 
{
    // Формируем нижний ряд пирамиды
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--)
    {
        float temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}

int main()
{
    float a[15] = {1.2, 2.3, 1.11, 3.4, 5.5, 5.4, 5.3, 5.1, 1.5, 1.25, 5.41, 5.31, 5.11, 1.51, 1.251};

    // Вывод элементов массива до сортировки
    for (int i = 0; i < 15; i++)
        std::cout << a[i] << "  ";
    std::cout << std::endl;

    heapSort(a, 15); // вызов функции сортировки

    // Вывод элементов массива после сортировки
    for (int i = 0; i < 15; i++)
        std::cout << a[i] << "  ";
    std::cout << std::endl;

}