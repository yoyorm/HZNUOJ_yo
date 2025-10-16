// Descriptions
// 我爱睡觉觉群里的花和雕很爱聊天。但是他们每天固定的上线时间并不同。
//给出他们每天固定的在线时间段，请问一天中他们能聊几个小时。
// Input
// 第一行输入一个T，代表有T组测试数据。
// 每组测试数据输入n(n代表花花在线的区间个数),m(代表雕在线的区间个数)
// 接下来n行输入区间[a,b] 代表花花的在线区间.接下来m行输入区间[c,d]代表雕的在线区间.时间范围为（0-23）。
// 注意：是闭区间，so，比如10-13，指花花10，11，12，13四个小时都在线
// Output
// 这一天他们可以聊天的总时间。
// Samples
// input 
// 1
// 3 2
// 10 13
// 14 17
// 20 23
// 13 15
// 21 23
// output 
// 6
// Hint
// 注意输入的时段可能会重合，比如10 13,10 12



#include <stdio.h>
void add(int *time, int start, int end);
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int time_h[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int time_d[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int h, d;
        int start, end;
        scanf("%d%d", &h, &d);
        while (h--)
        {
            scanf("%d%d", &start, &end);
            add(time_h, start, end);
        }
        while (d--)
        {
            scanf("%d%d", &start, &end);
            add(time_d, start, end);
        }

        int sum = 0;
        for (int i = 0; i < 24; i++)
        {
            if (time_h[i] == 1 && time_d[i] == 1)
            {
                sum++;
            }
        }
        printf("%d\n", sum);
    }
}
void add(int *time, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (time[i] == 0)
            time[i]++;
    }
}