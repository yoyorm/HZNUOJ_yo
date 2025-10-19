// Description
// 无聊的wxa又开始玩字符串了，现在他有一个字符串s,他想知道这个字符串是否含有非重叠AB和BA。(如ABA里AB和BA是重叠的，而ABBA里AB和BA是不重叠的)
// Input
// 输入数据有多组。
// 每组测试数据有一个字符串s。
// Output
// 如果可以找到AB和BA，输出”yu ye sa wang dai xing”，否则输出”zhen shi ou ba”
// Samples
// input
// ABA
// output
// zhen shi ou ba

#include <stdio.h>
#include <string.h>
int findAB(char *data, int discluded);
int findBA(char *data, int discluded);
int main()
{
    char data[1001];
    while (scanf("%s", data) != EOF)
    {
        if (findAB(data, -2) != -1 && findBA(data, findAB(data, -2)) != -1)
        {
            printf("yu ye sa wang dai xing\n");
        }
        else if (findBA(data, -2) != -1 && findAB(data, findBA(data, -2)) != -1)
        {
            printf("yu ye sa wang dai xing\n");
        }
        else
        {
            printf("zhen shi ou ba\n");
        }
    }
}

int findAB(char *data, int discluded)
{
    if (discluded == -1)
        return -1;
    for (int i = 0; i < strlen(data) - 1; i++)
    {
        if (discluded > -1)
        {
            if (i == discluded - 1 || i == discluded + 1)
            {
                continue;
            }
        }
        if (data[i] == 'A' && data[i + 1] == 'B')
        {
            return i;
        }
    }
    return -1;
}

int findBA(char *data, int discluded)
{
    if (discluded == -1)
        return -1;
    for (int i = 0; i < strlen(data) - 1; i++)
    {
        if (discluded > -1)
        {
            if (i == discluded - 1 || i == discluded + 1)
            {
                continue;
            }
        }
        if (data[i] == 'B' && data[i + 1] == 'A')
        {
            return i;
        }
    }
    return -1;
}
