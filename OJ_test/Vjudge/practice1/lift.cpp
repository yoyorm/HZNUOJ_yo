// https://www.luogu.com.cn/problem/P1135

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int height, A, B;
    cin >> height >> A >> B;
    vector<vector<long long>> map(height + 1, vector<long long>(height + 1, INT_MAX));
    vector<int> access(height + 1, INT_MAX);
    for (int i = 1; i <= height; i++)
    {
        cin >> access[i];
    }
    for (int i = 1; i <= height; i++)
    {
        if (i + access[i] <= height)
        {
            map[i][i + access[i]] = 1;
        }
        if (i - access[i] > 0)
        {
            map[i][i - access[i]] = 1;
        }
    }
    for (int i = 1; i <= height; i++)
    {
        map[i][i] = 0;
    }
    for (int count = 1; count <= height; count++)
    {
        for (int i = 1; i <= height; i++)
        {
            if (map[A][i] != INT_MAX)
            {
                for (int j = 1; j <= height; j++)
                {
                    map[A][j] = min(map[A][j], map[A][i] + map[i][j]);
                }
            }
        }
    }
    if (map[A][B] == INT_MAX)
        cout << -1;
    else
        cout << map[A][B];
}