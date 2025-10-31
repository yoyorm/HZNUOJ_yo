// Input
// 第一行输入一个T，代表有T组数据。
// 每组测试数据第一行输入n(0 < n < 10)和m(0 < m < 10)，代表他找了n份情书。
// 接下来n行，每行一句他摘抄的情书里面的话。接下来m行代表m次操作。
// ①A 1 2 表示把第二行情书接到第一行语句的后面。②C 1 2 表示把第二行的内容复制给第一行
// Output
// 输出完成操作后的第一行字符串
// Samples
// input
// 1
// 3 2
// I love you.
// You jump! I jump !
// Can you marry me?
// C 2 3
// A 1 2
// output
// I love you.Can you marry me?

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void addchar(char **sentence, int x, int y);
void copychar(char **sentence, int x, int y);
int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        int sentenceNum, verifyNum;
        scanf("%d %d", &sentenceNum, &verifyNum);
        getchar();
        char **sentence = (char **)malloc(sentenceNum * sizeof(char *));
        // 创建一个“二维字符数组”，其实就是一个字符串的数组，用来把所有词存起来
        for (int i = 0; i < sentenceNum; i++)
        {
            sentence[i] = (char *)malloc(10000 * sizeof(char));
            sentence[i][0] = '\0';
        }
        for (int i = 0; i < sentenceNum; i++)
        {
            fgets(sentence[i], 10000, stdin);
            sentence[i][strcspn(sentence[i], "\n")] = '\0';
            // 读取到换行就是一句话，手动处理多余的换行
        }
        while (verifyNum--)
        {
            char ch;
            int x, y;
            scanf("%c %d %d", &ch, &x, &y);
            getchar();
            switch (ch)
            // 分情况调用函数操作即可
            {
            case 'A':
                addchar(sentence, x, y);
                break;
            case 'C':
                copychar(sentence, x, y);
                break;
            }
        }
        printf("%s\n", sentence[0]);
        // 题目只要输出第一行

        for (int i = 0; i < sentenceNum; i++)
        {
            free(sentence[i]);
        }
        free(sentence); // 内存释放，没有也行
    }
    return 0;
}

void addchar(char **sentence, int x, int y)
{
    if (x <= 0 || y <= 0)
        return;
    int len_x = strlen(sentence[x - 1]);
    int len_y = strlen(sentence[y - 1]);
    if (len_x + len_y > 9999 || len_x <= 0 || len_y <= 0)
        return;
    // 处理意外情况，其实题目里不一定需要
    strncat(sentence[x - 1], sentence[y - 1], 9999 - len_x);
    // 直接拼接即可
    sentence[x - 1][len_x + len_y] = '\0';
}
void copychar(char **sentence, int x, int y)
{
    if (x <= 0 || y <= 0)
        return;
    int len_y = strlen(sentence[y - 1]);
    strncpy(sentence[x - 1], sentence[y - 1], 9999);
    // 复制一下
    sentence[x - 1][len_y] = '\0';
}