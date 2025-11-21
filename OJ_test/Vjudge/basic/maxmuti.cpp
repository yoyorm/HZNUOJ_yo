// https : // www.luogu.com.cn/problem/P1249
// 先发现规律，最大乘积是由从2开始尽可能连续自然数分解得到的
// 如有余数则从后往前将数字+1从而避免数字重复，例如10=2*3*(4+1);12=2*3*4;
// 分解得到一个数组的分解数字之后用高精度乘法求解即可
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string multiply(const string &a, const string &b)
{
    if (a == "0" || b == "0")
        return "0";
    // 特判 0
    string A = a, B = b;
    // 低位在前，方便进位
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    int lenA = A.size(), lenB = B.size();
    // 乘积最多 lenA+lenB 位
    string res(lenA + lenB, '0');

    // 逐位相乘 遍历A为乘数，B为被乘数
    for (int i = 0; i < lenA; ++i)
    {
        int carry = 0;
        int digitA = A[i] - '0';
        for (int j = 0; j < lenB; ++j)
        // 把A的每一位和B的每一位相乘，i也作为乘数位置的偏移量（同竖式乘法）
        {
            int temp = digitA * (B[j] - '0') + (res[i + j] - '0') + carry;
            res[i + j] = temp % 10 + '0';
            carry = temp / 10;
        }
        // 处理A每一位乘完后剩余的最高位的进位
        int k = lenB;
        while (carry)
        {
            int temp = (res[i + k] - '0') + carry;
            res[i + k] = temp % 10 + '0';
            carry = temp / 10;
            ++k;
        }
    }
    // 恢复高位在前
    reverse(res.begin(), res.end());
    // 去前导 0
    while (res.size() > 1 && res[0] == '0')
        res.erase(res.begin());
    return res;
}
int main()
{
    int num;
    cin >> num;

    vector<int> v;
    int temp = num;
    int i = 2;
    while (temp - i >= 0) // 从2开始分解，加上的自然数自增
    {
        temp -= i;
        v.push_back(i);
        i++;
    }
    int res = temp;
    while (res > 0) // 有剩余就从后往前 +1
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (res == 0)
                break;
            v[i] += 1;
            res -= 1;
        }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // 调用高精度求数组所有元素乘积
    string ans = "1";
    for (int i = 0; i < v.size(); i++)
    {
        ans = multiply(ans, to_string(v[i]));
    }
    cout << ans;
}

/*
//未使用高精度的模拟运行版本，发现规律，已弃用
#include <iostream>
#include <vector>
using namespace std;
long long sum(vector<int> v);
long long muti(vector<int> v);
int main()
{
    int num;
    cin >> num;
    int max = num;
    vector<int> res(1,1);
    for (int i = 2; i < num / 2+1; i++)
    {
        vector<int> v(i, 1);
        for (int j = 0; j < i; j++) // 初始化值1，2，3....
            v[j] += j;
        for (int j = 0; j < num / 2; j++) // 加1次数
        {
            for (int k = i - 1; k >= 0; k--) // 加1循环
            {
                v[k] += 1;
                if (sum(v) == num)
                {
                    if (muti(v) > max)
                    {
                        max = muti(v);
                        res = v;
                        break;
                    }
                }
                if (sum(v) > num)
                    break;
            }
        }
    }
    if (res.size() == 1)
        cout << num;
    else
    {
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }
    cout << endl;
    cout << max;
}

long long sum(vector<int> v)
{
    int sum = 0;
    int x = v.size();
    for (int i = 0; i < x; i++)
        sum += v[i];
    return sum;
}

long long muti(vector<int> v)
{
    int multi = 1;
    int x = v.size();
    for (int i = 0; i < x; i++)
        multi *= v[i];
    return multi;
}
*/