#include <stdio.h>
int main()
{
    int CurrentMoney = 0;
    int save = 0;
    int bill[12];
    for (int i = 0; i < 12; i++)
    {
        scanf("%d", &bill[i]);
    }
    for (int i = 1; i <= 12; i++)
    {
        CurrentMoney += 300;
        CurrentMoney -= bill[i - 1];
        if (CurrentMoney < 0)
        {
            printf("-%d", i);
            return 0;
        }
        int extra = CurrentMoney / 100;
        save += extra * 100;
        CurrentMoney -= extra * 100;
    }
    printf("%d", (int)(save * 1.2) + CurrentMoney);
}