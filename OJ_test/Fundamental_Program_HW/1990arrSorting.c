// Description
// Alex希望你可以帮助她用指针编写一个程序，可以对数组a的n个元素按绝对值从小到大进行排列。
// 输入的元素不会有a、-a同时出现的情况。
// Input
// 输入包含多组测试数据。
// 对于每组测试数据，先输入一个正整数N（N<10000），接下去输入N个绝对值小于100的整数。
// Output
// 排序后的数组。
// 每组测试数据之间用一个空行隔开。

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int T;
    while (scanf("%d", &T) == 1)
    {
        int *data = (int *)malloc(sizeof(int) * T);
        for (int i = 0; i < T; i++)
        {
            scanf("%d", &data[i]);
        }
        int change = 1;
        for (int i = 0; i < T; i++)
        {
            if (change == 0)
            {
                break;
            }
            change = 0;
            for (int *p = data; p < data + T - 1; p++) // 多减一防止访问越界
            {
                if (abs(*p) > abs(*(p + 1)))
                {
                    int temp = *p;
                    *p = *(p + 1);
                    *(p + 1) = temp;
                    change++;
                }
            }
        }
        for (int i = 0; i < T; i++)
        {
            if (i < T - 1)
            {
                printf("%d ", data[i]);
            }
            else
            {
                printf("%d\n", data[i]);
            }
        }
        printf("\n");
    }
}