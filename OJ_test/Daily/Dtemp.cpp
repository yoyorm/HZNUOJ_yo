#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        int count = 0;
        do
        {
            if (count == 0)
            {
                cout << s;
                count++;
            }
            else
            {
                cout << " " << s;
            }
        } while (next_permutation(s.begin(), s.end()));
        cout << endl;
    }
    return 0;
}