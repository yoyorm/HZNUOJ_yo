//https://www.luogu.com.cn/problem/P1328
//speical Rock Paper Scissors

//胜负情况直接查表
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int arr[5][5] = // 游戏的结果情况，1表示A赢，-1表示A输，0表示平
    {
        {0, -1, 1, 1, -1},
        {1, 0, -1, 1, -1},
        {-1, 1, 0, -1, 1},
        {-1, -1, 1, 0, 1},
        {1, 1, -1, -1, 0}};

int main()
{
    int A = 0, B = 0, num, a, b;
    cin >> num >> a >> b;
    vector<int> a_(a);
    vector<int> b_(b);
    for (int i = 0; i < a; i++)
    {
        cin >> a_[i];
    }
    for (int i = 0; i < b; i++)
    {
        cin >> b_[i];
    }
    for (int i = 0; i < num; i++)
    {
        int ashow = i % a;
        int bshow = i % b;
        if (arr[a_[ashow]][b_[bshow]] == 1)
        {
            A++;
        }
        else if (arr[a_[ashow]][b_[bshow]] == -1)
        {
            B++;
        }
        else
        {
            continue;
        }
    }

    cout << A << " " << B;
}