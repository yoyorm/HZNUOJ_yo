#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int one = 0;
    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        if (temp == 1)
            one++;
    }
    if (one == 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
}
