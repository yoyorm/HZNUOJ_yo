#include <bits/stdc++.h>
using namespace std;

string mul(const string &a, int b)
{
    string c;
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int digit = a[i] - '0';
        int product = digit * b + carry;
        c.push_back(product % 10 + '0');
        carry = product / 10;
    }

    while (carry)
    {
        c.push_back(carry % 10 + '0');
        carry /= 10;
    }

    reverse(c.begin(), c.end());
    return c;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> n >> target;

        string fact = "1";
        for (int i = 2; i <= n; ++i)
            fact = mul(fact, i);

        int cnt = 0;
        for (char ch : fact)
            if (ch - '0' == target)
                ++cnt;
        cout << cnt << endl;
    }
    return 0;
}