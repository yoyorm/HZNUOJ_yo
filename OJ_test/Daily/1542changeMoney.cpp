#include <iostream>
using namespace std;
int countit(int);
int main()
{
    int money;
    cin >> money;
    if (money < 8)
    {
        cout << 0;
        return 0;
    }
    else if (money == 8)
    {
        cout << 1;
        return 0;
    }
    else
    {
        cout << countit(money - 8);
        return 0;
    }
}

int countit(int money)
{
    int dp[1000] = {};
    dp[0] = 1;
    for (int i = 1; i <= money; i++)
    {
        dp[i] += dp[i - 1];
    }
    for(int i = 2; i <= money; i++)
    {
        dp[i] += dp[i - 2];
    }
    for(int i = 5; i <= money; i++)
    {
        dp[i] += dp[i - 5];
    }
    return dp[money];
}
