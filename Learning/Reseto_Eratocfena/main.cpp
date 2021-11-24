#include <iostream>
#include <cmath>
 
void vivod (int x, int n){//пока не достигнем границы проверяем число на делимость, если фунция возвращает true, то число простое
	for (int i = 0; i <= n; i++)
	{
		if (x!=0) std::cout<<x<<" ";
	}
	
}

int main()
{
	int n;
	std::cin>>n;
    int *a= new int [n+1];
    for (int i = 0; i < n; i++)
    {
        a[i]=i;
    }
    for (int i=2;i*i<n;i++){
        if (a[i]!=0){
            for (int j=i*i;j<=n;j+=i) a[i]=0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        x=a[i];
        vivod(x, n);
    }
    delete[] a;
	return 0;
}