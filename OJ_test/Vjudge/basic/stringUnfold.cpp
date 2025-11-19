// https : // www.luogu.com.cn/problem/P1098

// AI

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int a, b, c;
    cin >> a >> b >> c >> s;

    for (int i = (int)s.size() - 2; i > 0; --i)
    {
        if (s[i] != '-')
            continue;

        char L = s[i - 1], R = s[i + 1];
        bool isDigit = isdigit(L) && isdigit(R);
        bool isLower = islower(L) && islower(R);
        bool isUpper = isupper(L) && isupper(R);

        if (!isDigit && !isLower && !isUpper)
            continue;
        if (R <= L)
            continue; // 严格递增才展开

        /* 差1只删'-' */
        if (R == L + 1)
        {
            s.erase(i, 1);
            continue;
        }

        string fill;
        int step = (c == 1 ? 1 : -1);
        for (char ch = (c == 1 ? L + 1 : R - 1);
             c == 1 ? ch < R : ch > L;
             ch += step)
        {

            char use = ch;
            if (a == 3)
                use = '*'; // 全员星号
            else if (isDigit)
                use = ch; // 数字永远原样
            else if (a == 1)
                use = tolower(ch); // 字母→小写
            else if (a == 2)
                use = toupper(ch); // 字母→大写

            fill += string(b, use); // 重复b次
        }

        s.replace(i, 1, fill);
        /* 从后往前，无需调整i */
    }
    cout << s;
    return 0;
}