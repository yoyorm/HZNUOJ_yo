#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int num;
        scanf("%d", &num);
        int *arr = (int *)malloc(sizeof(int) * num);
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < num; i++)
        {
            int count = 0;
            while (!(arr[i] & 1))
            {
                count++;
                arr[i] = arr[i] >> 1;
            }
            if (i != num - 1)
            {
                printf("%d ", (int)pow(2, count));
            }
            else
            {
                printf("%d\n", (int)pow(2, count));
            }
        }
    }
}