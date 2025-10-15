#include <stdio.h>
int main()
{
    int data[4][4];
    int pos[2];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }
    int Min = data[0][0];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (data[i][j] < Min)
            {
                Min = data[i][j];
                pos[0] = i;
                pos[1] = j;
            }
        }
    }
    printf("%d %d", pos[0], pos[1]);
    return 0;
}