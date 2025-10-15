#include <stdio.h>
void sort(int data[]);
int main()
{
    int num[3];
    scanf("%d%d%d", &num[0], &num[1], &num[2]);
    sort(num);
    for (int i = 0; i < 3; i++)
    {
        char ch;
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'A':
            if (i != 2)
                printf("%d ", num[0]);
            else
                printf("%d", num[0]);
            break;
        case 'B':
            if (i != 2)
                printf("%d ", num[1]);
            else
                printf("%d", num[1]);
            break;
        case 'C':
            if (i != 2)
                printf("%d ", num[2]);
            else
                printf("%d", num[2]);
            break;
        }
    }
}

void sort(int data[])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            int temp;
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}