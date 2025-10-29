#include <stdio.h>
#include <stdlib.h>
struct node
{
    int *happy;
    int *time;
    struct node *next;
};

int howmuch(int *sumHappy, int *sumTime, int sumKind, int T);
void sortit(int *sumHappy, int *sumTime, double *HperT, int sumKind);

int main()
{
    int N, T;
    while (scanf("%d%d", &N, &T) == 2 && (N != 0 && T != 0))
    {
        int *endKind = (int *)malloc(sizeof(int) * N);
        struct node *start;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &endKind[i]);

            struct node *head = (struct node *)malloc(sizeof(struct node));
            head->happy = (int *)malloc(sizeof(int) * endKind[i]);
            head->time = (int *)malloc(sizeof(int) * endKind[i]);
            if (i == 0)
            {
                head->next = NULL;
            }
            else
            {
                head->next = start;
            }
            start = head;
            for (int j = 0; j < endKind[i]; j++)
            {
                scanf("%d", &head->happy[j]);
            }
            for (int j = 0; j < endKind[i]; j++)
            {
                scanf("%d", &head->time[j]);
            }
        }

        int sumKind = 0;
        for (int i = 0; i < N; i++)
        {
            sumKind += endKind[i];
        }
        int *sumHappy = (int *)malloc(sizeof(int) * sumKind);
        int *sumTime = (int *)malloc(sizeof(int) * sumKind);
        double *HperT = (double *)malloc(sizeof(double) * sumKind);
        struct node *current = start;
        int counter = 0;
        for (int i = 0; i < sumKind;)
        {
            for (int j = 0; j < endKind[counter]; j++)
            {
                sumHappy[i] = current->happy[j];
                sumTime[i] = current->time[j];
                HperT[i] = (double)sumHappy[i] / sumTime[i];
                i++;
            }
            counter++;
            if (current != NULL)
                current = current->next;
        }
        // for (int i = 0; i < sumKind; i++)
        // {
        //     printf("%d %d %.2f\n", sumHappy[i], sumTime[i], HperT[i]);
        // }

        sortit(sumHappy, sumTime, HperT, sumKind);
        printf("%d\n", howmuch(sumHappy, sumTime, sumKind, T));
    }
}

void sortit(int *sumHappy, int *sumTime, double *HperT, int sumKind)
{
    for (int i = 0; i < sumKind - 1; i++)
    {
        for (int j = 0; j < sumKind - 1 - i; j++)
        {
            if (HperT[j] < HperT[j + 1])
            {
                int temp = sumHappy[j];
                sumHappy[j] = sumHappy[j + 1];
                sumHappy[j + 1] = temp;

                temp = sumTime[j];
                sumTime[j] = sumTime[j + 1];
                sumTime[j + 1] = temp;

                double temp2 = HperT[j];
                HperT[j] = HperT[j + 1];
                HperT[j + 1] = temp2;
            }
        }
    }
}

int howmuch(int *sumHappy, int *sumTime, int sumKind, int T)
{
    int allHappy = 0;
    for (int i = 0; i < sumKind; i++)
    {
        if (sumTime[i] <= T)
        {
            allHappy += sumHappy[i];
            T -= sumTime[i];
        }
        if (T == 0)
            break;
    }
    return allHappy;
}