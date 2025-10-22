// Description
// 已知正整数
// n
// n 是两个不同的质数的乘积，试求出两者中较大的那个质数。
// Input
// 输入一个正整数
// n
// Output
// 输出一个正整数
// p
// p，即较大的那个质数。


#include <stdio.h>
#include <math.h>
int isPrime(long long n);
int main()
{

    long long n;
    scanf("%lld", &n);
    if (n % 2 == 0)
    {
        printf("%lld", n / 2);
        return 0;
    }
    for (long long x = 3; x <= sqrt(n); x += 2)
    {
        if (n % x == 0)
        {
            if (isPrime(x) && isPrime(n / x))
            {
                printf("%lld", n / x);
                return 0;
            }
        }
    }
}

int isPrime(long long n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0 && i != n)
            return 0;
    }
    return 1;
}