// Description
// zhengling知道很多生活小常识，比如如果我们是一个班的，那么我们手机号前面的几位数字一定是相同的
// 并且我们的电话号码长度是一样的。
// Input
// 输入N，表示有N个同学，接下来输入N行字符串表示每个同学的手机号。其中N<30，所有手机号码数据长度小于30。
// Output
// 假设所有N同学都是一个班的，请输出他们的手机号前面到底有多少位是相同的。
// Samples
// input
// 4
// 00209
// 00219
// 00999
// 00909
// output
// 2

#include <stdio.h>
#include <stdlib.h>
int finddiff(int *data[], short N, int length);
int main()
{
    short N;
    scanf("%hd", &N);
    getchar();
    int **data = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        data[i] = (int *)malloc(30 * sizeof(int));
    }
    int length;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            char ch;
            if ((ch = getchar()) != '\n')
            {
                data[i][j] = ch - '0';
            }
            else
            {
                length = j;
                break;
            }
        }
    }
    printf("%d", finddiff(data, N, length));
}

int finddiff(int *data[], short N, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (data[j][i] != data[j + 1][i])
            {
                return i;
            }
        }
    }
    return length;
}
