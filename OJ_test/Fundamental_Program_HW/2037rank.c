// 【C系列7.12】排名 AC 2037
// Description
// acm班的成绩出来的，要求你按照分数的高低进行降序排序，之后按照输入顺序输出每个人的排名。
// Input
// 输入一个n（n<=1000),表示人数，接下来的一行n个正整数，代表每一人的分数(小于等于1000)。
// Output
// 输出每一个人的排名。分数相同的按照输入先后排序。
// Samples
// input
// 3
// 10 9 12
// output
// 2 3 1
// Show after trying 4 times:
// input
// 10
// 408 284 262 265 398 955 818 556 108 309
// output
// 4 7 9 8 5 1 2 3 10 6

#include <stdio.h>
#include <stdlib.h>
void sortit(int *arr, int n);
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }
    sortit(temp, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (temp[j] != -1)
            {
                if (arr[i] == temp[j])
                {
                    if (i != n - 1)
                        printf("%d ", j + 1);
                    else
                    {
                        printf("%d", j + 1);
                    }
                    temp[j] = -1;
                    break;
                }
            }
        }
    }
}

void sortit(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
