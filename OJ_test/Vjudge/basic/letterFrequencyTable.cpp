// 题目描述
// 写一个程序从输入文件中去读取四行大写字母（全都是大写的，每行不超过 100 个字符），然后用柱状图输出每个字符在输入文件中出现的次数。严格地按照输出样例来安排你的输出格式。

// 输入格式
// 四行字符，由大写字母组成，每行不超过 100 个字符。

// 输出格式
// 由若干行组成，前几行由空格和星号组成，最后一行则是由空格和字母组成的。在任何一行末尾不要打印不需要的多余空格。不要打印任何空行。

// 输入
// THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
// THIS IS AN EXAMPLE TO TEST FOR YOUR
// HISTOGRAM PROGRAM.
// HELLO!
// 输出
//                             *
//                             *
//         *                   *
//         *                   *     *   *
//         *                   *     *   *
// *       *     *             *     *   *
// *       *     * *     * *   *     * * *
// *       *   * * *     * *   * *   * * * *
// *     * * * * * *     * * * * *   * * * *     * *
// * * * * * * * * * * * * * * * * * * * * * * * * * *
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
    vector<int> count(26, 0);
    for (int i = 0; i < 4; i++)
    {
        string s = "";
        getline(cin, s);
        for (int j = 0; j < s.size(); j++)
        // 读取每一个字母并且累加的对数组中
        {
            if (isalpha(s[j]))
            {
                count[s[j] - 'A']++;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < 26; i++)
    // 找出数据中最大的数字，作为后续图标的高度
    {
        if (max < count[i])
        {
            max = count[i];
        }
    }

    // 创建二维数组，通过bool 来记录每个字符的绘制情况
    bool **draw = new bool *[26];
    for (int i = 0; i < 26; i++)
    {
        draw[i] = new bool[max];
        for (int j = 0; j < max; j++)
        {
            draw[i][j] = false;
        }
    }

    for (int i = 0; i < 26; i++)
    // 根据数据大小来绘图，将要画的格子改为true
    {
        for (int j = 0; j < count[i]; j++)
        {
            draw[i][j] = true;
        }
    }

    for (int i = max - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        // 记得把宽和高互换一下让图标旋转一下，然后输出即可
        {
            if (draw[j][i])
            {
                if (j != 25)
                    cout << "* ";
                else
                    cout << "*";
            }
            else
            {
                if (j != 25)
                    cout << "  ";
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
    // 最后一行就输出字母
    printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
    for (int i = 0; i < 26; i++)
    {
        delete[] draw[i];
    }
}