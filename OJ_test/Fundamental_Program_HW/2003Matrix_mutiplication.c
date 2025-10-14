// Description
// 输入两个矩阵，输出两个矩阵相乘后的矩阵。（数据保证两个矩阵可相乘）。
// Input
// 输入n, m, k (0 <= n, m, k <= 20)，第一个矩阵的行数为n，列数为m。
// 第二个矩阵行数为m，列数为k。接下来n行，每行m个数，代表第一个矩阵，再接下来m行，每行k个数，代表第二个矩阵。
// Output
// 输出两个矩阵相乘后的矩阵。

#include <stdio.h>
#include <stdlib.h>
void input(int **a, int n, int m);
int **mutiply(int **a, int **b, int n, int m, int k);
int muti2(int **a, int **b, int n, int m, int k, int i, int j);
void output(int **c, int n, int k);
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int **a = (int **)malloc(n * sizeof(*a));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
    }
    int **b = (int **)malloc(m * sizeof(*b));
    for (int i = 0; i < m; i++)
    {
        b[i] = (int *)malloc(k * sizeof(int));
    }
    int **result = (int **)malloc(n * sizeof(*result));
    for (int i = 0; i < n; i++)
    {
        result[i] = (int *)malloc(k * sizeof(int));
    }

    input(a, n, m);
    input(b, m, k);
    result = mutiply(a, b, n, m, k);
    output(result, n, k);
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
    int **c = (int **)malloc(n * sizeof(*c));
    for (int i = 0; i < n; i++)
    {
        c[i] = (int *)malloc(k * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            c[i][j] = muti2(a, b, n, m, k, i, j);
        }
    }
    return c;
}

int muti2(int **a, int **b, int n, int m, int k, int i, int j)
{
    int sum = 0;
    for (int u = 0; u < m; u++)
    {
        sum += a[i][u] * b[u][j];
    }
    return sum;
}

void output(int **c, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}