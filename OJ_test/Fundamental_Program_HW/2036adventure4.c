#include <stdio.h>
#include <stdlib.h>

struct text
{
    unsigned long long key;
    char name[21];
};

void printText(struct text *data, int dataNum, int find);
int main()
{
    int dataNum, findNum;
    scanf("%d%d", &dataNum, &findNum);
    struct text *data = (struct text *)malloc(dataNum * sizeof(struct text));
    for (int i = 0; i < dataNum; i++)
    {
        scanf("%llu %s", &data[i].key, data[i].name);
    }
    for (int i = 0; i < findNum; i++)
    {
        int find;
        scanf("%d", &find);
        if (i != findNum - 1)
        {
            printText(data, dataNum, find);
            printf(" ");
        }
        else
        {
            printText(data, dataNum, find);
        }
    }
}

void printText(struct text *data, int dataNum, int find)
{
    for (int i = 0; i < dataNum; i++)
    {
        if (data[i].key == find)
            printf("%s", data[i].name);
    }
}