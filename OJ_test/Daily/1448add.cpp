// 最短加法 
// Description
// 给出一个数字n，使用若干个2，3，5，7累加，使其和刚好等于n，问至少需要用几个加数才能加出n。
// 例如：8可以写成：8=2+2+2+2；8=3+5。前者一共用了4个加数，后者只需用2个加数，因此8至少需要2个加数。
// Input
// 正整数n (2<=n<=1000)。
// Output
// 每次输出一行，即为所求答案。
// Samples
// input
// 2
// 8
// 11
// output
// 1
// 2
// 3

#include <iostream>
using namespace std;

int main()
{
    const int data[4] = {2, 3, 5, 7};
    int n;
    while (cin >> n)
    {
        int *dp = new int[n + 1];
        for (int i = 1; i <= n; i++)
            dp[i] = -1;
        dp[0] = 0;
        for (int datas : data)
        {
            for (int i = datas; i <= n; i++)
            {
                if (dp[i - datas] != -1)
                {
                    if (dp[i] == -1)
                        dp[i] = dp[i - datas] + 1;
                    else
                    {
                        dp[i] = min(dp[i], dp[i - datas] + 1);
                    }
                }
            }
        }
        cout << dp[n] << endl;
    }
}
