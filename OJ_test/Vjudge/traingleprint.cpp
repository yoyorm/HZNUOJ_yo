//G - 杨辉三角

// Description
// 给出 

// n(1≤n≤20)，输出杨辉三角的前 n 行。

// 如果你不知道什么是杨辉三角，可以观察样例找找规律。
// Sample 1
// Inputcopy	Outputcopy
// 6
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int **s = new int *[n + 2];
    for (int i = 0; i < n + 2; i++)
    {
        s[i] = new int[n + 2];
        for (int j = 0; j < n + 2; j++)
        {
            s[i][j] = 0;
        }
    }
    s[1][1] = 1;

    for (int i = 1; i < n + 2; i++)
    {
        for (int j = 1; j < n + 2; j++)
        {
            if (i == 1 && j == 1)
            {
                continue;
            }
            s[i][j] = s[i - 1][j] + s[i - 1][j - 1];
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j != i)
                cout << s[i][j] << " ";
            else
                cout << s[i][j];
        }
        cout << endl;
    }
}
