// Description
// 蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。
// Input
// 本题有多组数据，每组数据由一个正整数N组成。（N不大于100）
// Output
// 对于每一组数据，输出一个N行的蛇形矩阵。两组输出之间不要额外的空行。矩阵三角中同一行的数字用一个空格分开。行尾不要多余的空格。
// Samples

// input
// 5
// output
// 1 3 6 10 15
// 2 5 9 14
// 4 8 13
// 7 12
// 11

#include <iostream>
using namespace std;
void setline1(int *line1, int T);
void printline(int *line1, int T, int time);
int main()
{
    int T;
    while (cin >> T)
    {
        int *line1 = new int[T];
        setline1(line1, T);
        printline(line1, T, 0);
    }
}

void setline1(int *line1, int T)
// 初始化第一行数据
{
    int num = 0;
    for (int i = 0; i < T; i++)
    {
        num += i + 1;
        line1[i] = num;
    }
}

void printline(int *line1, int T, int time)
// 每次递归调用，打印起始位往后挪1，每个数字大小减去递归次数
{
    if (time < T)
    {
        for (int i = 0 + time; i < T; i++)
        {
            if (i != T - 1)
            {
                cout << line1[i] - time << " ";
            }
            else
            {
                cout << line1[i] - time;
            }
        }
        cout << endl;
        printline(line1, T, time + 1);
    }
    else
    {
        return;
    }
}
