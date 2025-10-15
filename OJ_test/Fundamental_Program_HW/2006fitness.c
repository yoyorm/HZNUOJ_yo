// Description
// 最近Linoy喜欢上玩一个换脸软件，她想黑黑队里的人。现在她知道各队员脸的吻合度，吻合度越高，换脸成功率也就越高。
// 你能帮她算出吻合度大于k的人有几对（不包括自身相换）吗？
// Input
// 第一行是一个t，代表有t组测试数据。
// 每组测试数据第一行是两个数据n(0 < n < 100)和k(0 <= k <= 100)
// 有n个队员，编号为0~n。接下来是n行n列，是各队员的吻合度。
// Output
// K吻合度以上的有几对。
// input:
// 1
// 5 78
// 100 78 98 67 87
// 78 100 78 23 84
// 98 78 100 68 65
// 67 23 68 100 25
// 87 84 65 25 100
// output:
// 3

#include <stdio.h>
#include <stdlib.h>
int JC(int n);
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int size, aim, count = 0;
        scanf("%d%d", &size, &aim);
        int **arr = (int **)malloc(size * sizeof(int *));
        for (int i = 0; i < size; i++)
            arr[i] = (int *)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        for (int i = 0; i < size; i++)
        {
            int pos = i + 1;
            for (int j = pos; j < size; j++)
            {
                if (arr[i][j] > aim)
                {
                    count++;
                }
            }
        }

        printf("%d\n", count);
    }
}
