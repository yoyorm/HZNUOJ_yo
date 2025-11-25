#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s.begin(), s.end(), cmp);

    string t = "";
    for (int i = 0; i < n; i++)
    {
        t += s[i];
    }
    while (t.size() > 1)
    {
        if (t[0] == '0')
        {
            t.erase(0, 1);
        }
        else
            break;
    }
    cout << t;
}
