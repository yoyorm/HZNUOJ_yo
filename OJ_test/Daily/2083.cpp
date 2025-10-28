// Description
// 曾小浪虽然短，但是他可以旋转！
// 曾小浪看见任何可以旋转的东西都会忍不住去转一转。这回他看到了矩阵，发现根本控制不住自己。请大家帮他一起旋转矩阵。
// Input
// 第一行输入一个整数T，代表后面有T组测试数据
// 每组测试数据第一行有三个数字n,m,k代表这是n行m列的矩阵，顺时针旋转（k*90）度
// 0<n,m,k<100
// 接下来n行，每行m个数字描述矩阵。
// Output
// 输出旋转后的矩阵。
// 每个样例之后空一行

#include <iostream>
using namespace std;
void turn_square(int **&square, int &n, int &m, int &k);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int **square = new int *[n];
        for (int i = 0; i < n; i++)
        {
            square[i] = new int[m];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> square[i][j];
            }
        }
        turn_square(square, n, m, k);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << square[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        for (int i = 0; i < n; i++)
        {
            delete[] square[i];
        }
        delete[] square;
    }
}

void turn_square(int **&square, int &n, int &m, int &k)
// 用引用参数便于数据修改
{
    k %= 4;
    while (k--)
    {
        // 注意temp的维度是旋转一次过后的维度
        int **temp = new int *[m];
        for (int i = 0; i < m; i++)
        {
            temp[i] = new int[n];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 顺时针旋转
                temp[i][j] = square[n - j - 1][i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            delete[] square[i];
        }
        delete[] square;
        square = temp; // 交换矩阵
        int t = n;     // 重新设置旋转过后的行列
        n = m;
        m = t;
    }
}