// 与小明一起玩回文串 AC

// Description
// 小明对字符串有自己独特的看法，他认为一个字符串是快乐的当且仅当这个字符串是一个回文串，（所谓回文串，就是它从前往后读和从后往前读的结果是一样的，如ababa就是一个回文串，而ababb就不是）。现在小明有许多的字符串，但其中可能有些不是快乐的。小明现在可以从每个字符串中删除一个字符，问这些字符串在经过这一次操作后是否是快乐的，若是，输出"Yes"，若不是，输出"No"。（若这个字符串已经是快乐的，小明可以不进行操作，直接输出"Yes"）
// Input
// 输入一个T，表示小明需要判断的字符串个数,数量小于100
// 接下来T行，每行一个字符串S，S的长度小于1000，且仅包含大小写字母。
// Output
// 对于每一个字符串，若已经是快乐的，或者可以通过删除一个字符而变成快乐的，则输出"Yes",反之，输出"No"
// Samples
// input
// 3
// ababa
// ababb
// abaa
// output
// Yes
// No
// Yes

#include <iostream>
#include <string>
using namespace std;
bool is_reserve(string &str);
int main()
{
    int num;
    cin >> num;
    while (num--)
    {
        string str;
        cin >> str;
        bool find = false;
        if (is_reserve(str))
        {
            cout << "Yes" << endl;
            continue;
        }
        int len = str.size();
        for (int i = 0; i < len; i++)
        // 逐个删除一个字符
        {
            char temp = str[i];
            str.erase(i, 1);
            if (is_reserve(str))
            {
                cout << "Yes" << endl;
                find = true;
                break;
            }
            else
            {
                // 不是回文串就还原
                str.insert(i, 1, temp);
            }
        }
        if (!find)
            cout << "No" << endl;
    }
}
bool is_reserve(string &str)
// 判断是否是回文串
{
    int len = str.size();
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return false;
        }
    }
    return true;
}
