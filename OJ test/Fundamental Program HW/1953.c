// Description
//
// 有个群叫我爱睡觉觉，里面有只雕每天早上都会说”早上好这个世界”，然后有朵花就排队型会说”早上好这个世界”。但是某只就会去破坏队形。每隔两天她都能成功破坏队形。假设第一天她成功破坏了队形，请问第n天她能不能成功破坏队形？
//
// Input
//
// 第一行输入一个T，表示有T组测试数据。（0 < T <= 10000)
//	每组测试数据第一行输入一个n，代表第n天。(0 < n <= 1000, 000, 000)
//
//	Output
//
//	对于每组数据输出一行字符串，如果某只成功破坏了队形，则输出”showshowshow”; 否则输出”forever love”.

#include <stdio.h>

int main()
{
    int T;
    scanf_s("%d", &T);
    int temp = 0;
    for (int i = 0; i < T; i++)
    {
        scanf_s("%d", &temp);
        if (temp % 3 == 1)
        {
            printf("showshowshow\n");
        }
        else
        {
            printf("forever love\n");
        }
    }

    return 0;
}