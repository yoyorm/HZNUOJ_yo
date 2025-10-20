#include <stdio.h>
typedef struct
{
    char name[21];
    int count;
} nickname;
void sortName(nickname loy[], int num);
int main()
{

    int T;
    scanf("%d", &T);
    while (T--)
    {
        nickname loy[100];
        int num;
        scanf("%d", &num);
        for (int i = 0; i < num; i++)
        {
            scanf("%s %d", loy[i].name, &loy[i].count);
        }
        sortName(loy, num);
        for (int i = num - 1; i >= 0; i--)
        {
            printf("%s\n", loy[i].name);
        }
    }
}

void sortName(nickname loy[], int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (loy[j].count > loy[j + 1].count)
            {
                nickname temp = loy[j];
                loy[j] = loy[j + 1];
                loy[j + 1] = temp;
            }
        }
    }
}