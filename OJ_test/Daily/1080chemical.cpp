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
        long long dp[35][7] = {};
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