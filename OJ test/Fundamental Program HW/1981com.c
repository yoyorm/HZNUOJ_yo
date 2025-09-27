#include <stdio.h>
int com(int x, int y);
int main()
{
    int a, b, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", com(a, b));
    }
    return 0;
}

int com(int x, int y)
{
    if (y == 0)
        return 1;
    long long result = 1;
    for (int i = 0; i < y; i++)
        result = result * (x - i) / (i + 1);
    // 使用*=会导致后面整除/而产生误差，先乘法后除避免问题
    return result;
}