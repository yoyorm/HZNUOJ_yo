// Description
// ACM队吉祥物cjc学长因为一次做了太猥琐的事，被学嫂罚去写检讨书300字，于是他开挂去网上找样本，
// 但是样本中的名字不一样会有破绽，现在需要你来帮忙替换样本中的名字name为学嫂的名字doctorZ。
// Input
// 先输入一个T,代表有T组数据。
// 每组测试数据有一个数据name(0 < name < 20)，表示样本中的名字。
// 接下来一行输入检讨书内容(name < s < 1000)。
// Output
// 修改后的内容。
// Samples
// input
// 1
// mwy
// Dear mwy, do not be angry, I love you! I should not be so wretched, I was wrong, please forgive me. In the future, I will absolutely obey the leadership of you!
// output
// Dear doctorZ, do not be angry, I love you! I should not be so wretched, I was wrong, please forgive me. In the future, I will absolutely obey the leadership of you!
// Hint
//  在单词中出现name也需要替换！

#include <stdio.h>
#include <string.h>

void tag(char *name, char *words);
void verify(char *words);

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    char name[21];
    char words[1001];
    while (T--)
    {
        scanf("%s", name);
        getchar();
        fgets(words, 1001, stdin);
        tag(name, words);
        verify(words);
    }
    return 0;
}

void tag(char *name, char *words)
// 把name标签替换成%
{
    char start1 = name[0];
    char start2 = 'n';
    short words_len = strlen(words);
    short name_len = strlen(name);
    for (int i = 0; i < words_len; i++)
    {
        if (words[i] == start1 || words[i] == start2)
        {

            if (!strncmp(words + i, name, name_len))
            {
                words[i] = '%';
                for (int j = i + 1; j < i + name_len; j++)
                {
                    words[j] = '-';
                }
            }
            if (!strncmp(words + i, "name", 4))
            {
                words[i] = '%';
                for (int j = i + 1; j < i + 4; j++)
                {
                    words[j] = '-';
                }
            }
        }
    }
}

void verify(char *words)
// 把%替换成doctorZ 其余部分跳过
{
    for (int i = 0; i < strlen(words); i++)
    {
        if (words[i] == '%')
        {
            printf("doctorZ");
        }
        else if (words[i] == '-')
        {
            continue;
        }
        else
        {
            printf("%c", words[i]);
        }
    }
}