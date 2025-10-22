// 【C系列7.10】结构-10 女神历险记3
// Description

// 进了古墓之后，小队又遭遇到了重重机关，但都一一化险为夷。直到在一条密道中行走的时候，somebody碰到了某个机关，瞬间密道开始坍塌，大家必须马上离开密道。由于先前已经破译出地图，现在已经得知了各个门离他们位置的距离。不幸的是之前还得知了这种门一旦第一个人通过就会开始闭合，并且每个门闭合时间可能不同。幸运的是你已经得到了这些门闭合的具体时间和队伍中跑得最快和最慢的人的速度。由于某些原因，你们必须集体行动；又由于某些原因，密道中你们一旦开始跑就不能停下；还由于某些原因，只有你能算出最好的逃生之门，一切的重担都落在了你的身上。

// Input

//  输入第一行为一个整数n(0<n<=100)，代表有n个门。其后有n行，每行有两个整数，第一个是门离你们队伍的距离，第二个是门闭合所需要的时间。最后有一行有两个整数，分别队伍中的最慢速度和最快速度。

// Output

//  如果有多个门可以逃生，输出到距离最小的能逃生的门的最慢的人所需要的时间(保留两位小数)；若没有能成功逃生的门，输出”let_s_die_together”（输出不用加双引号）;

// Samples

// input
// 3
// 10 2
// 5 3
// 15 20
// 2 3
// output
// 2.50

#include <stdio.h>
#include <stdlib.h>

struct door
{
    double distance;
    int time;
};
void sort(struct door *data, int num);
float calc(double distance, int time, int min, int max);
double find(struct door *data, int num, int min, int max);
int main()
{
    int num;
    scanf("%d", &num);
    struct door *data = (struct door *)malloc(sizeof(struct door) * num);
    for (int i = 0; i < num; i++)
    {
        scanf("%lf %d", &data[i].distance, &data[i].time);
    }
    sort(data, num);

    int speedMax, speedMin;
    scanf("%d %d", &speedMin, &speedMax);

    double Time = find(data, num, speedMin, speedMax);
    if (Time >= 0)
        printf("%.2f", Time);
    else
        printf("let_s_die_together");
    return 0;
}

void sort(struct door *data, int num)
// 直接把距离从小到大排序
{
    struct door temp;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (data[j].distance > data[j + 1].distance)
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

float calc(double distance, int time, int min, int max)
// 计算最慢的人能否到达
{
    double delta = (distance / max + time) - distance / min;
    if (delta >= 0)
    {
        return delta;
    }
    else
    {
        return -1;
    }
}

double find(struct door *data, int num, int min, int max)
// 遍历寻找第一个可以通过的门，然后输出最慢的人所需要时间
{
    int i = 0;
    for (i; i < num; i++)
    {
        int delta = calc(data[i].distance, data[i].time, min, max);
        if (delta >= 0)
            return data[i].distance / min;
    }
    return -1;
}