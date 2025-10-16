// Description
// cjc和mwy是队里公认的情侣，他们有一个孩子叫wjn。他们为孩子的教育而操心，这一天他们教wjn比较单词。比较规则是优先比较单词的长度，单词长的单词为大。
// 如果单词长度相同则比较单词大小（字典序大的单词为大）。
// Input
// 第一行是一个T，代表有T组测试样例。
// 每组测试样例，第一行输入一个n(0 < n < 50)，代表有n个单词相比较。接下来n行输入n个单词(单词长度不超过20)。
// Output
// 输出最大的单词。
// Sample
// input
// 1
// 3
// zz
// wzj
// wxa
// output
// wzj

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findlength(char **data, int num);
int compare(char **data, int num, int maxLength);
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        short num;
        scanf("%hd", &num);
        char **data = (char **)malloc(sizeof(char *) * num);
        for (int i = 0; i < num; i++)
        {
            data[i] = (char *)malloc(sizeof(char) * 21);
            data[i][20] = '\0';
            scanf("%s", data[i]);
        }
        int pos = compare(data, num, findlength(data, num));
        printf("%s\n", data[pos]);
    }
    return 0;
}
int findlength(char **data, int num)
{
    int maxLength = 0;
    for (int i = 0; i < num; i++)
    {
        if (strlen(data[i]) > maxLength)
        {
            maxLength = strlen(data[i]);
        }
    }
    return maxLength;
}

int compare(char **data, int num, int maxLength)
{
    int count = 0;
    int pos = 0;
    char temp[1000];
    for (int i = 0; i < num; i++)
    {
        if (strlen(data[i]) == maxLength)
        {
            if (count == 0)
            {
                strcpy(temp, data[i]);
                pos = i;
                count++;
            }
            else
            {
                if (strcmp(temp, data[i]) < 0)
                {
                    strcpy(temp, data[i]);
                    pos = i;
                }
            }
        }
    }
    return pos;
}