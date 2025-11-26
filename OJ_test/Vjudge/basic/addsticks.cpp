// https://www.luogu.com.cn/problem/P1149

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num, count = 0;
    cin >> num;
    num -= 4;
    vector<int> v = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for (int i = 10; i <= 10000; i++)
    {
        int first = i / 10;
        int second = i % 10;
        v.push_back(v[first] + v[second]);
    }

    for (int i = 0; i < 5000; i++)
    {
        for (int j = 0; j < 5000; j++)
        {
            if (v[i] + v[j] + v[i + j] == num)
            {
                count++;
            }
        }
    }

    cout << count;
}