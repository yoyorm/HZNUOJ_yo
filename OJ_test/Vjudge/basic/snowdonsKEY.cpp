// 题目描述
// 2013 年 X 月 X 日，俄罗斯办理了斯诺登的护照，于是他混迹于一架开往委内瑞拉的飞机。但是，这件事情太不周密了，因为 FBI 的间谍早已获悉他的具体位置——但这不是最重要的——最重要的是如果要去委内瑞拉，那么就要经过古巴，而经过古巴的路在美国的掌控之中。
// 丧心病狂的奥巴马迫降斯诺登的飞机，搜查时却发现，斯诺登杳无踪迹。但是，在据说是斯诺登的座位上，发现了一张纸条。纸条由纯英文构成：Obama is a two five zero.（以 . 结束输出，只有 6 个单词 + 一个句号，句子开头如没有大写亦为合法）这句话虽然有点无厘头，但是警官陈珺骛发现这是一条极其重要的线索。他在斯诺登截获的一台笔记本中找到了一个 C++ 程序，输入这条句子后立马给出了相对应的密码。陈珺鹜高兴得晕了过去，身为警官的你把字条和程序带上了飞机，准备飞往曼哈顿国际机场，但是在飞机上检查的时候发现——程序被粉碎了！飞机抵达华盛顿只剩 5 分钟，你必须在这 5 分钟内编写（杜撰）一个程序，免受上司的 10000000000mod10 大板。破译密码的步骤如下：
// 找出句子中所有用英文表示的数字 (≤20)，列举在下：
// 正规：one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty
// 非正规：a both another first second third
// 为避免造成歧义，another 算作 1 处理。
// 将这些数字平方后对 100 取模，如 0→0→00，5→25→25，19→361→61。
// 把这些两位数（按任意顺序）按数位排成一行，组成一个新数，如果开头为 0，就去 0，如 {00,25,61}→2561。
// 找出所有排列方法中最小的一个数，即为密码。
// 输入格式
// 一个含有 6 个单词的句子。

// 保证整个句子的字符个数（包括空格）不超过 1000。

// 输出格式
// 一个整型变量（密码）。如果没有符合要求的数字出现，则输出 0。
// 输入输出样例
// 输入
// Black Obama is two five zero .
// 输出
// 425

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string word;
    vector<string> excel;
    // 通过vector存储两个数字的整体，便于后续两个数字为一组的排序
    while (cin >> word && word != ".")
    {
        if (word == "zero")
        {
            excel.push_back("00");
        }
        else if (word == "one")
        {
            excel.push_back("01");
        }
        else if (word == "two")
        {
            excel.push_back("04");
        }
        else if (word == "three")
        {
            excel.push_back("09");
        }
        else if (word == "four")
        {
            excel.push_back("16");
        }
        else if (word == "five")
        {
            excel.push_back("25");
        }
        else if (word == "six")
        {
            excel.push_back("36");
        }
        else if (word == "seven")
        {
            excel.push_back("49");
        }
        else if (word == "eight")
        {
            excel.push_back("64");
        }
        else if (word == "nine")
        {
            excel.push_back("81");
        }
        else if (word == "ten")
        {
            excel.push_back("00");
        }
        else if (word == "eleven")
        {
            excel.push_back("21");
        }
        else if (word == "twelve")
        {
            excel.push_back("44");
        }
        else if (word == "thirteen")
        {
            excel.push_back("69");
        }
        else if (word == "fourteen")
        {
            excel.push_back("96");
        }
        else if (word == "fifteen")
        {
            excel.push_back("25");
        }
        else if (word == "sixteen")
        {
            excel.push_back("56");
        }
        else if (word == "seventeen")
        {
            excel.push_back("89");
        }
        else if (word == "eighteen")
        {
            excel.push_back("24");
        }
        else if (word == "nineteen")
        {
            excel.push_back("61");
        }
        else if (word == "twenty")
        {
            excel.push_back("00");
        }
        else if (word == "a" || word == "both" || word == "another" ||
                 word == "first" || word == "second" || word == "third")
        {
            excel.push_back("01");
        }
    }
    if (excel.size() == 0)
    {
        cout << "0";
        return 0;
    }
    sort(excel.begin(), excel.end());
    string t = "";
    for (int i = 0; i < excel.size(); i++)
    {
        t += "99";
    }

    // 比较大小，取小的之后，更换下一个vector的下一个字典序
    do
    {
        string temp = "";
        for (int i = 0; i < excel.size(); i++)
        {
            temp += excel[i];
        }
        if (temp < t)
        {
            t = temp;
        }
    } while (next_permutation(excel.begin(), excel.end()));
    bool first = 0;

    while (!first && t.size() > 1)
    {
        if (t[0] == '0')
        {
            t.erase(0, 1);
        }
        else
        {
            first = true;
        }
    }
    cout << t;
}
