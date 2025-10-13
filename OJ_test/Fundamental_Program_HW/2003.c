#include <stdio.h>
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int **a = (int *)malloc(n * sizeof(*a));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
    }
    int **b = (int *)malloc(m * sizeof(*b));
    for (int i = 0; i < m; i++)
    {
        b[i] = (int *)malloc(k * sizeof(int));
    }

    input(a, n, m);
    input(b, m, k);
}

void input(int **a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

int **mutiply(int **a, int **b, int n, int m, int k)
{
    int **c = (int *)malloc(n * sizeof(*c));
    for (int i = 0; i < n; i++)
    {
        c[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = ;
        }
    }
}

int muti2(int **a, int **b, int n, int m, int k, int i, int j)
{
    for (int u = 0; u < m; u++)
}
