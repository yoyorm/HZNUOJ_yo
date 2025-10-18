// Description
// 明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N <= 100），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。
// 然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。
// 请你协助明明完成“去重”与“排序”的工作
// Input
// 每组输入数据的第一行含有一个正整数N，表示后面行中有N个随机整数。若N = 0，表示处理结束。
// Output
// 对应每组输入数据，输出一组数据，该数据由单独一行开头，内含一个N，表示后面有N个排好序的整数，整数之间空一格。
// 每组输出数据之间空一行。
// Samples
// input
// 12
// 2 4 6 17 20 40 43 45 60 64 85 98
// 17
// 35 75 40 61 56 21 85 61 50 83 52 22 44 68 51 80 38
// 0
// output
// 12
// 2 4 6 17 20 40 43 45 60 64 85 98
//
// 16
// 21 22 35 38 40 44 50 51 52 56 61 68 75 80 83 85

#include <iostream>
using namespace std;
void tag(int *data, int T);
void sortDATA(int *data, int T);
void printDATA(int *data, int T);
int main()
{
    int T;
    while (cin >> T && T != 0)
    {
        int *data = new int[T];
        for (int i = 0; i < T; i++)
        {
            cin >> data[i];
        }
        tag(data, T);
        sortDATA(data, T);
        printDATA(data, T);
        cout << endl
             << endl;
    }

    return 0;
}

void tag(int *data, int T)
//将重复的数字标记为0
{
    for (int i = 0; i < T; i++)
    {
        for (int j = i + 1; j < T; j++)
        {
            if (data[i] == data[j])
            {
                data[j] = 0;
            }
        }
    }
}

void sortDATA(int *data, int T)
//对数据进行冒泡排序
{
    for (int i = 0; i < T - 1; i++)
    {
        for (int j = 0; j < T - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    int count = 0;
}

void printDATA(int *data, int T)
//打印数据，跳过0数据
{
    int count = 0;
    for (int i = 0; i < T; i++)
    {
        if (data[i] != 0)
        {
            count++;
        }
    }
    cout << count << endl;
    for (int i = 0; i < T; i++)
    {
        if (data[i] != 0)
        {
            cout << data[i] << " ";
        }
    }
}