#include <iostream>
using namespace std;
long long jump(int x, int y, int n, int value);

const int x_move[4] = {1, -1, 0, 0};
const int y_move[4] = {0, 0, 1, -1};

const int map[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int step;
int main()
{

    int pos_x = 0, pos_y = 0;
    cin >> pos_x >> pos_y;
    pos_x--;
    pos_y--;
    cin >> step;
    cout << jump(pos_x, pos_y, 0, map[pos_x][pos_y]) << endl;
}

long long jump(int x, int y, int n, int value)
{
    long long sum = 0;
    if (step == n)
    {
        return value;
    }
    for (int i = 0; i < 4; i++)
    {
        // 通过修改下标实现上下左右移动
        int new_x = x + x_move[i];
        int new_y = y + y_move[i];

        if (new_x >= 0 && new_x < 3 && new_y >= 0 && new_y < 3)
        // 保证没有超出格子边界
        {
            sum += jump(new_x, new_y, n + 1, value * map[new_x][new_y]);
            // 每次还可以移动，就递归调用，把当前值value更新后传给下一层
            // 当走的次数到了，就会返回最后的value
            // sum可以把后续所有方向可能的sum累加起来
        }
    }
    return sum; // 把后面的value返回给前面的函数
}