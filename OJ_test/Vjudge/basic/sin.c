// Description
// 输入一组勾股数 abc
//用分数格式输出其较小锐角的正弦值。（要求约分。）

// Input
// 一行，包含三个正整数，即勾股数 

// a,b,c（无大小顺序）。

// Output
// 一行，包含一个分数，即较小锐角的正弦值

#include <stdio.h>
int findMAX(long long a, long long b, long long c);
int findMIN(long long a, long long b, long long c);
int find_divide(long long a, long long b);
int main()
{
    long long a, b, c, x, y, z;
    scanf("%lld %lld %lld", &a, &b, &c);
    x = findMIN(a, b, c);
    y = findMAX(a, b, c);
    z = find_divide(x, y);
    printf("%lld/%lld", x / z, y / z);
}

int findMAX(long long a, long long b, long long c)
{
    long long max = a;
    long long temo[3] = {a, b, c};
    for (int i = 0; i < 3; i++)
    {
        if (temo[i] > max)
        {
            max = temo[i];
        }
    }
    return max;
}

int findMIN(long long a, long long b, long long c)
{
    long long min = a;
    long long temo[3] = {a, b, c};
    for (int i = 0; i < 3; i++)
    {
        if (temo[i] < min)
        {
            min = temo[i];
        }
    }
    return min;
}

int find_divide(long long a, long long b)
{
    long long temp = 0;
    for (int i = 1; i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
            temp = i;
    }
    return temp;
}