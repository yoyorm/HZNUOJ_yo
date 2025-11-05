#include <iostream>
using namespace std;
void torch(int x, int y, bool **a);
void light(int x, int y, bool **a);
int main()
{
    int n, k, m;
    cin >> n >> m >> k;
    bool **a = new bool *[n + 4];
    for (int i = 0; i < n + 4; i++)
    {
        a[i] = new bool[n + 4];
        for (int j = 0; j < n + 4; j++)
        {
            a[i][j] = false;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x += 2;
        y += 2;
        torch(x, y, a);
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x += 2;
        y += 2;
        light(x, y, a);
    }
    int sum = 0;
    for (int i = 2; i <= n + 1; i++)
    {
        for (int j = 2; j <= n + 1; j++)
        {
            if (!a[i][j])
                sum++;
        }
    }
    cout << sum;
}

void torch(int x, int y, bool **a)
{
    a[x][y] = true;
    a[x][y + 1] = true;
    a[x][y - 1] = true;
    a[x + 1][y] = true;
    a[x - 1][y] = true;
    a[x + 1][y + 1] = true;
    a[x + 1][y - 1] = true;
    a[x - 1][y + 1] = true;
    a[x - 1][y - 1] = true;
    a[x + 2][y] = true;
    a[x - 2][y] = true;
    a[x][y + 2] = true;
    a[x][y - 2] = true;
}
void light(int x, int y, bool **a)
{
    for (int i = x - 2; i <= x + 2; i++)
    {
        for (int j = y - 2; j <= y + 2; j++)
        {
            a[i][j] = true;
        }
    }
}