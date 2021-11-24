#include <iostream>
#include <vector>

int main()
{
    std::vector<int> a = {-1,10,-20,-3};

	int result = a[0];
	int left_ind = 0;
	int right_ind = 0;
	int sum = 0;
	int minus_pos = -1;
	for (int i = 0; i < a.size(); ++i) 
	{
		sum += a[i];
 		if (sum > result)
		{
			result = sum;
			left_ind = minus_pos + 1;
			right_ind = i;
		}
 
		if (sum < 0)
		{
			sum = 0;
			minus_pos = i;
		}
	}
    std::cout << left_ind << " and " << right_ind;
}