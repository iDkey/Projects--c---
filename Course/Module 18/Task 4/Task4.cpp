#include <iostream>

void evendigits(long long num, int* p_ans)
{
    int remainder = num % 10;
    if (remainder % 2 == 0)
    {
        *p_ans += 1;
        if (num / 10 > 0)
        evendigits(num / 10, p_ans);
    }
    else
        if (num / 10 > 0)
        evendigits(num / 10, p_ans);
}

int main()
{
    long long num = 9223372036854775806;
    int ans = 0;
    int* p_ans = &ans;
    evendigits(num, p_ans);
    std::cout << ans;
}