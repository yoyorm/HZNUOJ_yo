// 【C系列综合1】游戏达人I AC 2041

// Description
// ACM队的ydw是个游戏的狂热爱好者，他喜好玩各种各样的单机游戏，以可以得到各种不同的结局通关为乐，但是由于时间有限（他还要出题TAT），于是他只能选择自己喜欢的几个结局来通关，由于ydw是游戏达人，因此他可以自己搞定所有的剧情而不去查攻略，但是由于自力更生，完成每个结局的时间是不同的，而他对每一个结局的喜好度也是不同的，即通关每个结局他获得的愉悦度是不同的。他希望在自己有限的时间内可以通关某些结局来使得自己的愉悦度最大。

// Input
// 有多组测试数据，
// 第1行为N（0<N<=100）和T(0<T<=2000)，表示ydw有N个游戏可以玩，玩游戏的总的时间为T。
// 接下来3*N行，每行第一个数字n(1<=n<=10)表示这个游戏有几种结局，接下来的一行n个数字表示通关某个结局ydw可以获得的愉悦度，再接下来一行的n个数字表示ydw通关某个结局需要的时间。
// 测试数据以0 0结尾。（数据保证愉悦度和时间均大于0，小于等于1000）
// Output
// ydw可以获得的最大愉悦度。
// Samples
// input
// 1 10
// 2
// 3 5
// 4 6
// 1 9
// 2
// 3 5
// 4 6
// 0 0
// output
// 8
// 5

// Hint
// 第1组数据中，ydw有10的时间去玩1个游戏，2个结局分别耗时为4和6，而愉悦度为3和5，刚好可以达到，则愉悦度为8。
// 第2组中，时间为9，只能玩1个结局，则最大为5。

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int *happy;
    int *time;
    struct node *next;
};

int howmuch(int *sumHappy, int *sumTime, int sumKind, int T);

int main()
{
    int N, T;
    while (scanf("%d%d", &N, &T) == 2 && (N != 0 && T != 0))
    {
        int *endKind = (int *)malloc(sizeof(int) * N); // 存储所有游戏的结局数
        struct node *start;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &endKind[i]);

            struct node *head = (struct node *)malloc(sizeof(struct node));
            // 创建链表存储每个结局的数据
            head->happy = (int *)malloc(sizeof(int) * endKind[i]);
            head->time = (int *)malloc(sizeof(int) * endKind[i]);
            if (i == 0)
            {
                head->next = NULL;
            }
            else
            {
                head->next = start;
            }
            start = head;
            for (int j = 0; j < endKind[i]; j++)
            {
                scanf("%d", &head->happy[j]);
            }
            for (int j = 0; j < endKind[i]; j++)
            {
                scanf("%d", &head->time[j]);
            }
        }

        int sumKind = 0;
        for (int i = 0; i < N; i++)
        {
            sumKind += endKind[i]; // 统计所有结局数
        }
        int *sumHappy = (int *)malloc(sizeof(int) * sumKind);
        int *sumTime = (int *)malloc(sizeof(int) * sumKind);
        struct node *current = start;
        int counter = 0;
        for (int i = 0; i < sumKind;)
        // 将所有结局数据统一存储在一个大数组中
        {
            for (int j = 0; j < endKind[counter]; j++)
            {
                sumHappy[i] = current->happy[j];
                sumTime[i] = current->time[j];
                i++;
            }
            counter++;
            if (current != NULL)
                current = current->next;
        }
        // for (int i = 0; i < sumKind; i++)
        // {
        //     printf("happy:%d time:%d ave:%.2f\n", sumHappy[i], sumTime[i], HperT[i]);
        // }

        printf("%d\n", howmuch(sumHappy, sumTime, sumKind, T));
    }
}

int howmuch(int *sumHappy, int *sumTime, int sumKind, int T)
{
    int *timetable = (int *)malloc(sizeof(int) * (T + 1));
    for (int i = 0; i < T + 1; i++)
    {
        timetable[i] = -1;
        // 用-1区分还没有数据的时间节点
    }
    timetable[0] = 0;
    for (int i = 0; i < sumKind; i++)
    {
        int happy = sumHappy[i];
        int time = sumTime[i];
        for (int j = T; j >= time; j--)
        // 从后向前，避免重复用2次一个结局
        {
            if (timetable[j - time] != -1)
            {
                if (timetable[j] < timetable[j - time] + happy)
                // 在原来的基础上加上新的happy，大于旧值则更新
                {
                    timetable[j] = timetable[j - time] + happy;
                }
            }
            // for (int i = 0; i <= T; i++)
            // {
            //     printf("%d ", timetable[i]);
            //     if (i == T)
            //         printf("\n");
            // }
        }
    }

    int max = -1;
    for (int i = 0; i <= T; i++)
    // 找到所有时间段中间最大值
    {
        if (timetable[i] > max)
        {
            max = timetable[i];
        }
    }
    free(timetable);
    return max;
}