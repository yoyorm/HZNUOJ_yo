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
        for (int i = 0; i < sentenceNum; i++)
        {
            sentence[i] = (char *)malloc(10000 * sizeof(char));
            sentence[i][0] = '\0';
        }
        for (int i = 0; i < sentenceNum; i++)
        {
            fgets(sentence[i], 10000, stdin);
            sentence[i][strcspn(sentence[i], "\n")] = '\0';
        }
        while (verifyNum--)
        {
            char ch;
            int x, y;
            scanf("%c %d %d", &ch, &x, &y);
            getchar();
            switch (ch)
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
        for (int i = 0; i < sentenceNum; i++)
        {
            free(sentence[i]);
        }
        free(sentence);
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
    strncat(sentence[x - 1], sentence[y - 1], 9999 - len_x);
    sentence[x - 1][len_x + len_y] = '\0';
}
void copychar(char **sentence, int x, int y)
{
    if (x <= 0 || y <= 0)
        return;
    int len_y = strlen(sentence[y - 1]);
    strncpy(sentence[x - 1], sentence[y - 1], 9999);
    sentence[x - 1][len_y] = '\0';
}