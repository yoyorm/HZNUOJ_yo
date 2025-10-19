#include <stdio.h>
#include <stdlib.h>
void verify(char *data, int *Np);
int main()
{
    int N;
    int *Np = &N;
    scanf("%d", &N);
    getchar();
    char *data = (char *)malloc(N * sizeof(char));
    for (int i = 0; i < N; i++)
    {
        scanf("%c", &data[i]);
    }
    verify(data, Np);
    printf("%d\n", *Np);
    return 0;
}

void verify(char *data, int *Np)
{
    for (int i = 0; i < *Np - 1; i++)
    {
        if (data[i] != data[i + 1])
        {
            for (int j = i; j < *Np - 2; j++)
            {
                data[j] = data[j + 2];
            }
            *Np = *Np - 2;
            i = -1;
        }
    }
}
