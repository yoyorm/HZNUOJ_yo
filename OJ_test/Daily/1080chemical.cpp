// 化学品问题
//  Tags:
// Time Limit:  1 s      Memory Limit:   128 MB
// Submission：325     AC：52     Score：99.54

  
// Description

// 一个实验室有N个放化学品的试管，排列在一条直线上。如果连续M个试管中放入药品，则会发生爆炸，于是，在某些试管中可能不放药品。
// 任务：对于给定的N和M，求不发生爆炸的放置药品的方案总数

// Input

// 第一行是一个正整数L，代表输入数据的组数
// 接下来L行，每行有两个正整数N，M( 1＜N＜32，2≤M≤5)

// Output

// 输出L行，每行只有一个正整数S，表示对应输入数据的方案总数。


#include <iostream>
using namespace std;

int main()
{
    int T;
    int N, L;
    cin >> T;
    while (T--)
    {
        cin >> N >> L;
        long long dp[35][9] = {};
        dp[0][0] = 1;

        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j < L; ++j)
                dp[i][0] += dp[i - 1][j];

            for (int j = 0; j + 1 < L; ++j)
                dp[i][j + 1] += dp[i - 1][j];
        }
        long long sum = 0;
        for (int k = 0; k < L; k++)
            sum += dp[N][k];
        cout << sum << endl;
    }
}
// #include <cstdio>
// #include <vector>
// using namespace std;
// bool check(vector<int> &v, int n, int l);
// void fill(int n, int l, vector<int> &v, int pos, int &count);

// int main()
// {
//     int t;
//     scanf("%d", &t);
//     while (t--)
//     {
//         int count = 0;
//         int n, l;
//         scanf("%d %d", &n, &l);
//         vector<int> v(0);
//         fill(n, l, v, 0, count);
//         printf("%d\n", count);
//     }
// }
// bool check(vector<int> &v, int pos, int l)
// {

//     int sum = 0;
//     for (int i = pos; i >=0&&i>pos-l; i--)
//     {

//         if (v[i] == 1)
//             sum++;
//         else
//             break;
//         if (sum >= l)
//             return false;
//     }
//     return true;
// }
// void fill(int n, int l, vector<int> &v, int pos, int &count)
// {
//     if (pos >= n)
//     {
//         count++;
//         return;
//     }
//     v.push_back(1);
//     if (check(v, pos, l))
//     {
//         fill(n, l, v, pos + 1, count);
//     }
//     v.pop_back();

//     v.push_back(0);
//     fill(n, l, v, pos+1, count);
//     v.pop_back();
// }