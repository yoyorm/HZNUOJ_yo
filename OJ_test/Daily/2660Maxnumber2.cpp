// 最大的数Ⅱ AC
// Description
//       kk参加了算法考试，遇到一道题，题目说给你一个数字n，让你删掉其中的k位，使得剩下的数字最大，比如给出的数字n是987654，k为3，则删去后剩下的数字应该是987，kk觉得老师出的题太简单了，他给这道题加了一个条件，就是不可以删去数字0.但是他只会出题不会写题，你能帮他完成这道题吗？
// Input
// 多组输入。
// 输入n和k，n表示原数字，k表示要删去几个数字。
// n的长度最大为5000.k保证小于非0数的个数。
// Output
// 对于每组输入，都有一行输出。
// 输出为删去后的最大数。
// Samples

// input
// 112233 3
// 34056 2
// output
// 233
// 406
// input
// 7202 1
// 7232 1
// output
// 720
// 732

#include <iostream>
#include <string>
using namespace std;
// 思路：保证所有被0分割的数字段都是降序排列，然后如果还要删除数字就从后往前删小的（高位肯定对数字影响更大）
int main()
{

    string s;
    int num;
    while (cin >> s >> num)
    {
        string result = "";
        // 用来放答案

        for (int i = 0; i < s.length(); i++)
        // 从头到尾遍历
        {
            char current = s[i];
            // 如果下一个数字比已经放入的数字要大，就把前面小的数字扔掉
            // 这么做可以保证数字是严格递减的直到遇到0，即把较大位的小数字删了
            while (num > 0 && !result.empty() && current > result.back() && result.back() != '0')
            // 注意答案变量是空的，以及0不能被扔掉
            {
                result.pop_back();
                num--;
            }

            result.push_back(current);
            // 依次添加下一个数字
        }

        while (num > 0 && !result.empty())
        {
            if (result.back() != '0')
            {
                // 删除末尾的数字
                result.pop_back();
                num--;
            }
            else
            {
                // 遇到0了就跳过，从后往前删掉非0数字（之前已经降序过啦）
                for (int i = result.size() - 1; i >= 0; i--)
                {
                    if (num == 0)
                        break;
                    if (result[i] != '0')
                    {
                        result.erase(i, 1);
                        num--;
                    }
                }
            }
        }

        if (result.empty())
        {
            cout << "0\n";
        }
        else
        {
            cout << result << "\n";
        }
    }
    return 0;
}