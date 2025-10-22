// 【C系列7.14】她的困难
// Description
//  给你N个数字，求出唯一一个出现次数为奇数的数值。
// Input
// 第一行输入一个整数t，代表有多少个数据。
// 之后每一组测试数据第一行输入一个n（0<n<1000000)，代表n个数字，之后输入n个数字（每一个数字小于10^9）。
// Output
// 输出出现次数为奇数的数字。
// Samples
// input
// 1
// 3
// 1 1 2
// output
// 2

#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int num;
        scanf("%d", &num);
        int sum = 0;
        while (num--)
        {
            int temp;
            scanf("%d", &temp);
            sum ^= temp;
            // 一个数字和自己位异或后为0
        }
        printf("%d\n", sum);
    }
}