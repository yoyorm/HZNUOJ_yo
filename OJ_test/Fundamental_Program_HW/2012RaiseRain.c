#include <stdio.h>
int raiseRain(int data[10], int startPos);
int main()
{
    int data[10];
    int temp = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &data[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        if (raiseRain(data, i) > temp)
        {
            temp = raiseRain(data, i);
        }
    }
    printf("%d", temp);
}

int raiseRain(int data[10], int startPos)
{
    int count = 1;
    int temp = data[startPos];
    for (int i = startPos; i < 10; i++)
    {
        if (data[i] > temp)
        {
            count++;
            temp = data[i];
        }
    }
    return count;
}