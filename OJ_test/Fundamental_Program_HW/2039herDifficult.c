#include <stdio.h>

void verifyData(long long *arr, int size);
void check(long long arr);
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int num;
        scanf("%d", &num);
        long long arr = 0;
        for (int i = 0; i < num; i++)
        {
            long long size;
            scanf("%lld", &size);
            verifyData(&arr, size);
        }
        check(arr);
    }
}

void verifyData(long long *arr, int size)
{
    *arr ^= (1 << size);
}

void check(long long arr)
{
    int count = 0;
    while (count < 10e9)
    {
        int bit = (arr >> count) & 1;
        if (bit == 1)
        {
            printf("%d", count);
            return;
        }
        else
        {
            count++;
        }
    }
}