#include <iostream> 
#include <algorithm> // для std::sort()
 
int main()
{
	const int length = 5;
	int array[length] = { 30, 50, 20, 10, 40 };
 
	std::sort(array, array+length);
 
	for (int i=0; i < length; ++i)
		std::cout << array[i] << ' ';
 
	return 0;
}
