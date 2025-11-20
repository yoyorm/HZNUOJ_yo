// https://www.luogu.com.cn/problem/P1045
// cpp20 O2神力助我AC，不然会TLE哈哈
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void minusNum(string &a)
{
    int carry = 1;
    for (int i = 0; i < 500 && carry; i++)
    {
        int temp = (a[i] - '0') - carry;
        if (temp < 0)
        {
            temp += 10;
            a[i] = temp + '0';
            carry = 1;
        }
        else
        {
            a[i] = temp + '0';
            carry = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;

    int digits = (int)(n * log10(2.0)) + 1;
    cout << digits << "\n";

    string a(500, '0');
    a[0] = '1';
    int count = 0;
    long long times = 0;
    const int MAX_POWER = 30;
    //在longlong的范围内，尽可能缩减循环次数，计算2的固定高次方
    while (n >= MAX_POWER)
    {
        int carry = 0;
        for (int j = 0; j < 500; j++)
        {
            long long temp = (long long)(a[j] - '0') * (1073741824) + carry;
            carry = temp / 10;
            a[j] = (temp % 10) + '0';
        }
        n -= MAX_POWER;
    }

    for (int i = 0; i < n; i++)
    {
        int carry = 0;
        for (int j = 0; j < 500; j++)
        {
            long long temp;
            temp = (a[j] - '0') * 2 + carry;
            carry = temp / 10;
            a[j] = temp % 10 + '0';
        }
    }
    minusNum(a);

    reverse(a.begin(), a.end());
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 50; j++)
        {
            cout << a[count];
            count++;
        }
        cout << "\n";
    }
}