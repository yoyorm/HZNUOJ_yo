// 【C系列7.13】她的思考 AC 2038
// Description
// C(n, 0) = C(n, n) = 1 对所有的n>0
// C(n, k) = C(n − 1, k − 1) + C(n − 1, k) 对所有 0 < k < n.
// 求C(n, k)与2的余数。
// Input
// 一行输入一个整数t，代表有多少组数据。接下来的t行输入两个整数k，n(0 ≤ k ≤ n < 2^31, n > 0)。
// Output
// C(n, k)与2的余数。
// Samples
// input
// 2
// 1 1
// 1 2
// output
// 1
// 0
// Show after trying 4 times:
// input
// 5
// 284 408
// 262 265
// 398 955
// 556 818
// 108 309
// output
// 0
// 0
// 0
// 0
// 0

#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long k, n;
        scanf("%lld %lld", &k, &n);
        if (k == 0 || k == n)
        {
            printf("1\n");
            continue;
        }
        if ((n & k) == k)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
}
