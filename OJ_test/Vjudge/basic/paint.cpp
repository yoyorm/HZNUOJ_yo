// https://www.luogu.com.cn/problem/P3392

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int paint(vector<string> &a, int white, int blue, int red)//计算在行颜色确定的情况下要刷多少次
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {

            if (i <= white && a[i][j] != 'W')
            {
                count++;
            }
            else if (i <= blue && i > white && a[i][j] != 'B')
            {
                count++;
            }
            else if (i <= red && i > blue && a[i][j] != 'R')
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<string> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    int minnum = INT_MAX;
    for (int i = 0; i < m - 2; i++)//直接列举所有行颜色的可能（颜色到第几行结束）
    {
        for (int j = i + 1; j < m - 1; j++)
        {
            int k = m - 1;
            minnum = min(minnum, paint(a, i, j, k));
        }
    }
    cout << minnum;//输出最小值
}
