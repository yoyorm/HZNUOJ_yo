// Description
// 话说现在猪肉价格这么贵，wxa也开始了养猪生活。
// 说来也奇怪，他养的猪一出生第二天开始就能每天中午生一只小猪，而且生下来的竟然都是母猪。
// 不过光生小猪也不行，wxa采用了一个很奇特的办法来管理他的养猪场：
// 对于每头刚出生的小猪，在它生下第二头小猪后立马被杀掉，卖到超市里。
// 假设在创业的第一天，wxa只买了一头刚出生的小猪，请问，在第N天晚上，wxa的养猪场里还存有多少头猪？
// Input
// 测试数据的第一行是一个正整数T，代表测试数据的个数。
// 接下来有T组测试，每组测试数据占一行，分别是一个正整数N，代表wxa创业的第N天。（0<N<20）
// Output
// 对于每组数据，请在一行里输出第N天晚上养猪场里猪的数目。

#include <stdio.h>
void pigNum(int newpig, int wait, int dead, const short day, int count);
int pig = 0; // 使用全局变量，获得递归内层返回值
int main()
{
    int T;
    scanf("%d", &T);
    short day;
    while (T--)
    {
        pig = 0;
        scanf("%hd", &day);
        if (day == 1)
        {
            printf("1\n");
            continue;
        }
        else
        {
            pigNum(1, 0, 0, day, 2);
            printf("%d\n", pig);
        }
    }
}

void pigNum(int newpig, int wait, int dead, const short day, int count)
{
    if (count <= day)
    {
        int temp = newpig;
        newpig += wait;
        dead = wait;
        wait = temp; // 按照将死状态传递数量
        count++;
        pigNum(newpig, wait, dead, day, count);
        // 未到指定天数就继续递归
    }
    else
    {
        if (count == day + 1) // 只有当天的数目可以传递出来
            pig = newpig + wait;
    }
}