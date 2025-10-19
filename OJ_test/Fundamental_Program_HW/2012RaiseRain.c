// Description
// 6月的雨总是来得莫名其妙淅淅沥沥根本停不下来，就在这种让人烦躁的季节，MWY毅然决然的选择通过计算他自己定义的“最大上升天数”来判断自己是否需要甩了CJC。“最大上升天数”的意思是，在连续的十天内，如果下雨时长数组是{2，1，3，4，5，6，7，8，1，10}，第一天时长大于第二天，所以{2，1}是下降的，而{2}或{1}是上升的并且只有一个元素，所以前两天的最大上升天数是1。前三天的上升天数是2，应为{2，3}或者{1，3}（请注意{1，3},是符合的）是上升的并且在上升的序列里面有两个元素。请帮MWY写一个计算最大上升函数的代码。
// Input
// 十个整数N，用空格隔开(1<=N<=24)
// Output
// 输出最大上升天数。
// Samples
// input
// 12 11 7 24 1 7 9 8 10 22
// output
// 5

// 涉及动态规划
#include <stdio.h>
int raiseRain(int *);
int main()
{
    int data[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &data[i]);
    }
    printf("%d", raiseRain(data));
}

int raiseRain(int data[10])
{
    int temp[10]; // 保存每一位的最大上升天数
    for (int i = 0; i < 10; i++)
    {
        temp[i] = 1;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[j] < data[i] && temp[j] + 1 > temp[i])
            // 搜索前面的数字，如果比当前数字小，并且比当前数字的上升天数大，则更新上升天数给自己
            {
                temp[i] = temp[j] + 1;
            }
        }
    }
    int max = temp[0];
    for (int i = 1; i < 10; i++)
    // 找到最大上升天数
    {
        if (max < temp[i])
        {
            max = temp[i];
        }
    }
    return max;
}
