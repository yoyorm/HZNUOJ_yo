#include<iostream>
using namespace std;
bool isPowerOfTwo(long long num);

int main()
{
    long long num;
    while (cin >> num)
    {
        if (num >= 1 && (num == 1 || isPowerOfTwo(num) || num % 1024 == 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

bool isPowerOfTwo(long long num)
{

    if (num <= 0) return false;
    while (num > 1)
    {
        if (num % 2 != 0)
            return false;
        num /= 2;
    }
    return true;
}