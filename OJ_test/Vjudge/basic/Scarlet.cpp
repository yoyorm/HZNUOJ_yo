//https://www.luogu.com.cn/problem/P4924


#include <iostream>
#include <vector>

using namespace std;
void printV(vector<vector<int>> &v);
void changeV(vector<vector<int>> &v, int posx, int posy, const int r, const int dir);
int main()
{
    int n;
    int times;
    cin >> n >> times;
    vector<vector<int>> v(n, vector<int>(n));
    int tempCount = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)

        {
            v[i][j] = tempCount;
            tempCount++;
        }
    }
    // printV(v);
    while (times--)
    {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        changeV(v, x, y, r, z);
    }
    printV(v);
}

void printV(vector<vector<int>> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
                cout << v[i][j] << " ";
            else
                cout << v[i][j];
        }
        cout << endl;
    }
}

void changeV(vector<vector<int>> &v, int posx, int posy, const int r, const int dir)
{
    int n = v.size();
    const int x = posx - 1;
    const int y = posy - 1;
    const int N = 2 * r + 1;
    vector<vector<int>> t(N, vector<int>(N));
    for (int i = x - r; i <= x + r; i++)
    {
        for (int j = y - r; j <= y + r; j++)
        {
            t[i - x + r][j - y + r] = v[i][j];
        }
    }
    vector<vector<int>> T(N, vector<int>(N));
    if (dir == 0) // 顺时针
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                T[j][N - i - 1] = t[i][j];
            }
        }
    }
    else if (dir == 1) // 逆时针
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                T[N - j - 1][i] = t[i][j];
            }
        }
    }
    // 修改回原数组
    for (int i = x - r; i <= x + r; i++)
    {
        for (int j = y - r; j <= y + r; j++)
        {
            v[i][j] = T[i - x + r][j - y + r];
        }
    }
}