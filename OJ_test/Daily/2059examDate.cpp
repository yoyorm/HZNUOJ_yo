// 【排序与查找】愚蠢的菜豚 AC
// Description
// 菜豚挂了n门课，老师们安排好了他的补考时间，根据老师的安排，菜豚可以在第ai天参加第i场考试。但他知道补考并没有什么用，他想早点考完。老师每门课都给了他一个提前考的时间bi，因此他能在第ai天或bi天参加第i场考试(bi<ai)，并且他可以一天考多门课。但是老师要求他的考试顺序必须是按照ai非递减的顺序考。
// 那么菜豚最少能在第几天能考完所有的考试呢？
// Input
// 第一行输入一个整数n(0<n<10001)
// 接下来n行，每行有2个数字字：ai bi  (0<ai<10^9) (0<bi<10^9)
// Output
// 输出答案
// Samples
// input
// 3
// 5 2
// 3 1
// 4 2
// output
// 2
// Hint
//  如果样例为：
// 3
// 5 2
// 3 2
// 4 3
// 答案则为5, 根据ai的顺序 菜豚会在第2天考第二门，第3天考第三门，第5天考第一门。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void sortit(vector<int> &ai, vector<int> &bi);
int main()
{
    int x;
    cin >> x;
    // 将ai和bi存在两个数组中
    vector<int> ai(x, 0), bi(x, 0);
    for (int i = 0; i < x; i++)
    {
        cin >> ai[i];
        cin >> bi[i];
    }
    sortit(ai, bi);
    // 把考试按照正常日期ai排序，保证顺序
    vector<int> ans(0);
    // 存放考试日期的数组
    ans.push_back(bi[0]);
    int pos = 0;
    for (int i = 1; i < x; i++)
    {
        // 如果考试的提前日期bi大于前一次考试的日期，才可以放入
        if (bi[i] >= ans[pos])
        {
            ans.push_back(bi[i]);
        }
        else
        {
            ans.push_back(ai[i]);
        }
        pos++;
    }
    cout << ans[pos];
    // 直接把最后一天考试的日期输出即可
}

void sortit(vector<int> &ai, vector<int> &bi)
{
    int len = ai.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (ai[j] > ai[j + 1])
            {
                swap(ai[j], ai[j + 1]);
                swap(bi[j], bi[j + 1]);
            }
            if (ai[j] == ai[j + 1])
            // 注意ai相等的时候，要判断bi的大小排序
            // 不然会因为先选了大的日期而影响选择最小的最优解
            {
                if (bi[j] > bi[j + 1])
                {
                    swap(bi[j], bi[j + 1]);
                }
            }
        }
    }
}