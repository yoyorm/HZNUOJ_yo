// Description
// 大家都知道zz特别喜欢金鱼，一天zz去买金鱼，但是他只带了n元，他想买k种金鱼。(每种一条)如果钱不够他会向wxa借。
// 已知每条金鱼的价格，你能告诉他最少他需要向wxa借多少吗？
// Input
// 第一行输入一个T，代表有T组测试数据。
// 每组测试数据第一行输入n,k,m(0 < m < 1000)。接下来有一行，有m组数据，代表总共有m种金鱼。
// Output
// zz向wxa借的钱。
// Samples
// input
// 1
// 10 5 10
// 1 2 3 4 5 6 7 8 9 10
// output
// 5

#include <stdio.h>
#include <stdlib.h>
int MINprice(int *money, int kind);
void sort(int *price, int all);
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int money, kind, all;
        scanf("%d%d%d", &money, &kind, &all);
        int *price = (int *)malloc(all * sizeof(int));
        for (int i = 0; i < all; i++)
        {
            scanf("%d", &price[i]);
        }
        sort(price, all);
        int need = MINprice(price, kind);
        if (money >= need)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", need - money);
        }
        free(price);
    }
}
// 实现从小到大排序
void sort(int *price, int all)
{
    for (int i = 0; i < all - 1; i++)
    {
        for (int j = 0; j < all - 1 - i; j++)
        {
            if (price[j] > price[j + 1])
            {
                int temp = price[j];
                price[j] = price[j + 1];
                price[j + 1] = temp;
            }
        }
    }
}
// 找最便宜的五条
int MINprice(int *money, int kind)
{
    int sum = 0;
    for (int i = 0; i < kind; i++)
    {
        sum += money[i];
    }
    return sum;
}