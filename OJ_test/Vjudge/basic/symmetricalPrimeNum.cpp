// 题目描述
// 因为 151 既是一个质数又是一个回文数（从左到右和从右到左是看一样的），所以 151 是回文质数。

// 写一个程序来找出范围 [a,b](5≤a<b≤100,000,000)（一亿）间的所有回文质数。

// 输入格式
// 第一行输入两个正整数 a 和 b。

// 输出格式
// 输出一个回文质数的列表，一行一个。


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool is_huiwen(long long n)
{
    string s = to_string(n);
    int len = s.size();
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

bool is_prime(long long n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0)
        return false;

    long long limit = sqrt(n);
    for (long long i = 11; i <= limit; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    long long x, y;
    cin >> x >> y;

    if (x % 2 == 0)
        x++;

    for (long long i = x; i <= y; i += 2)
    {
        if (is_huiwen(i) && is_prime(i))
        {
            cout << i << endl;
        }
    }

    return 0;
}