#include <iostream>
using namespace std;
long long memory[67];
long long count_machstick(int n);
int main()
{
    for (int i = 0; i < 67; i++)
    {

        memory[i] = -1;
    }
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << count_machstick(n) << endl;
    }
}

long long count_machstick(int n)
{

    if (n >= 1)
    {
        if (memory[n] != -1)
        {
            return memory[n];
        }
        else
        {
            return memory[n] = count_machstick(n - 1) + count_machstick(n - 2) + count_machstick(n - 3) + count_machstick(n - 4);
        }
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}