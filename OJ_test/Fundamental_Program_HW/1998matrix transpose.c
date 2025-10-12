#include <stdio.h>
void change(int a[3][3]);
int main()
{
    int data[3][3];
    while (scanf("%d%d%d", &data[0][0], &data[0][1], &data[0][2]) == 3)
    {
        scanf("%d%d%d", &data[1][0], &data[1][1], &data[1][2]);
        scanf("%d%d%d", &data[2][0], &data[2][1], &data[2][2]);
        change(data);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", data[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

void change(int a[3][3])
{
    int temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}
