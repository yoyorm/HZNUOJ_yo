// Description
// 在一个N*N的方阵中，填入1，2，……N，共N*N（N≤10）个数，并要求构成如下的格式：
// 例：
// N=5

// 13 14 15 16  1

// 12 23 24 17  2

// 11 22 25 18  3

// 10 21 20 19  4

//  9  8  7  6  5

// N=6

// 16 17 18 19 20  1

// 15 30 31 32 21  2

// 14 29 36 33 22  3

// 13 28 35 34 23  4

// 12 27 26 25 24  5

// 11 10  9  8  7  6

#include <iostream>
using namespace std;

int main()
{
    short N;
    cin >> N;
    short **A = new short *[N];
    for (short i = 0; i < N; i++)
    {
        A[i] = new short[N];
    }
    int count = 1;
    int top = 0, bot = N - 1, lef = 0, rig = N - 1;
    // 通过上下左右四个边控制写入范围
    while (top <= bot && lef <= rig)
    {
        // 循环顺序同题目即可下左上右一圈
        for (int i = top; i <= bot; i++)
        {
            A[i][rig] = count;
            count++;
        }
        rig--;
        for (int i = rig; i >= lef; i--)
        {
            A[bot][i] = count;
            count++;
        }
        bot--;
        for (int i = bot; i >= top; i--)
        {
            A[i][lef] = count;
            count++;
        }
        lef++;
        for (int i = lef; i <= rig; i++)
        {
            A[top][i] = count;
            count++;
        }
        top++;
    }

    for (short i = 0; i < N; i++)
    {
        for (short j = 0; j < N; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}