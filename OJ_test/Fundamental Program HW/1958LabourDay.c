// Description

// 每年五一学校们就纷纷开始放假， wzj说：“如果五一放5天的假，那么如果五一当天是星期一，加上两个周末，不就有9天的假期了！如果是五一当天是星期二，加上后面连着的周末，就有6天的假期！这样的话每年的五一放假的天数都有可能不同，让我来算算各个年的五一连续放几天假！”，当然并不存在放假却不补课的学校，但是wzj开心地算了起来。

// Input

//  输入有多组数据，第一行输入一个T表示有T组数据，每组数据里，含一个数字year（1928 <= year <= 9999），表示年份。

// Output

//  对于每组数据，输出那一年的五一加上连在一起的周末的放假天数。

#include <stdio.h>
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int y;
        scanf("%d", &y);
        int W = 0, c, d, m;
        c = y / 100;
        m = 5;
        d = 1;
        y %= 100;
        W = (y + y / 4 + c / 4 - 2 * c + (26 * (m + 1) / 10) + d - 1) % 7;
        if (W < 0)
        {
            W += 7;
        }
        int day = 0;
        switch (W)
        {
        case 0:
            day = 5 + 1;
            break;
        case 1:
            day = 5 + 4;
            break;
        case 2:
            day = 4 + 2;
            break;
        case 3:
            day = 3 + 2;
            break;
        case 4:
            day = 5;
            break;
        case 5:
            day = 5;
            break;
        case 6:
            day = 5;
            break;
        }
        printf("%d\n", day);
    }
}