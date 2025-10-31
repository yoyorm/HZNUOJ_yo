// Description

// 天气逐渐变冷，年老体弱的越越鸟打算去南方某座温度适宜的城市过冬，但由于翅膀严重老化，最远飞行距离有限，请你为可怜的越越鸟计算飞行所需的最短距离，以让它能做好心理准备。

// Input

// 输入包含多组测试数据。

// 每组输入第一行为两个正整数n（n<=20）和m（m<=n*(n-1)/2），n表示城市个数，m表示线段个数。（线段为两个城市间的连接线）

// 接下来m行，每行输入三个整数a，b，和l（l<=10^9），表示a市与b市之间存在一条线段，线段长度为l。（a与b不同）

// 每组最后一行输入两个整数x和y，表示问题：x为越越鸟现在所在的城市，y为越越鸟打算飞往过冬的城市。城市标号为1~n。

// Output

// 对于每组输入，输出x市与y市之间的最短距离，如果x市与y市之间非连通，则输出“No path”。

// Samples

// input
// 4 4
// 1 2 4
// 1 3 1
// 1 4 1
// 2 3 1
// 2 4
// output
// 3

// 运用了Floyd最短路径算法

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    const int INF = 1e9;
    short n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> map(n + 2, vector<int>(n + 2));
        //使用二维数组的两个下标表示从a到b，值为距离
        for (int i = 0; i < n + 2; i++)
        {
            for (int j = 0; j < n + 2; j++)
            {
                if (i == j)
                    map[i][j] = 0;
                    //自己到自己的距离为0
                else
                {
                    map[i][j] = INF;
                    // 不通的路标记为“无穷大”
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            map[a][b] = d;
            map[b][a] = d;
        }

        for (int k = 1; k <= n; k++)
        // 每次i到j都把所有点当作桥试一次，看看会不会更短
        {
            for (int i = 1; i <= n; i++)
            //循环 便利每一个点到所有点的可能距离
            {
                for (int j = 1; j <= n; j++)
                {
                    if (map[i][j] > map[i][k] + map[k][j])
                    // 只要可以通过走其他路径来缩短距离，就把路径更新
                    {
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }
        int x, y;
        cin >> x >> y;
        if (map[x][y] == INF)
        //最短距离没有更新过，还是默认的无穷大就是走不通
        {
            cout << "No path" << endl;
        }
        else
        {
            cout << map[x][y] << endl;
        }
    }
}