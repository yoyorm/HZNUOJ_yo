// 【数据结构】最大子列和
// Description
// 给定n个整数组成的序列n1,n2,n3.....nn，“连续子列”被定义为{ni,n(i+1)....n(j)}，其中 1≤i≤j≤n。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。

// Input

// 第一行一个数字n

// 表示有几个数字

// 接下来一行有n个数字 表示n1，n2,n3...nn的值

// Output
// 在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0

// Samples

// input
// 6
// -2 11 -4 13 -5 -2
// output
// 20

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<int> v(num);
    for (int i = 0; i < num; i++)
    {
        cin >> v[i];
    }
    vector<int> dp(num, 0);
    for (int i = 0; i < num; i++)
    {
        int sum = 0;
        for (int j = 0; (j + i) < num; j++)
        {
            sum += v[i + j];
            dp[i] = max(dp[i], sum);
        }
    }
    sort(dp.begin(), dp.end(), greater<int>());
    cout << dp[0] << endl;
}