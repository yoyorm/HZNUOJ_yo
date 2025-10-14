// Description
// cyn小朋友今天学会了如何爬楼梯，但她腿太短了，能走的步数不多，你能帮她算算他的走法总共有几种吗？
// 假设有h个楼梯，一次只能走一步或者两步或者三步，求总共有几种不同的方法
// Input
// 第一行输入一个整数T，代表有几组测试数据。
// 接下来每行输入一个整数h(less than 30)，代表有几个楼梯。
// Output
// 输出有几种方法。
#include <stdio.h>

int count(int h);
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int h;
        scanf("%d", &h);
        printf("%d\n", count(h));
    }
}

int count(int h)
{
    int result = 0;
    int a = 1;
    int b = 1;
    int c = 2;
    switch (h)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    }
    for (int i = 3; i <= h; i++)
    {
        result = a + b + c;
        a = b;
        b = c;
        c = result;
    }
    return result;
}