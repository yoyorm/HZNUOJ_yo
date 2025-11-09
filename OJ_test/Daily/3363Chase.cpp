// 警犬C+1追鹅战士 AC
// Description
// 警犬正在追击鹅战士，两者之间有一定的初始距离。追击路径上设有若干障碍，每个障碍属于不同的类型，不同类型的障碍会使得警犬停留不同的时间。如果在规定的时间内警犬成功追上鹅战士，则追击成功；否则，追击失败。
// 追击规则：
// 警犬从位置 0 开始，鹅战士从位置 P 开始。
// 警犬和鹅战士以恒定速度 v1 和 v2 移动。
// 警犬遇到障碍时，必须停留对应的时间。
// 如果在时间 T 内警犬的位置 ≥ 鹅战士的位置，则追击成功；否则，追击失败。
// Input

// 第一行：5个整数 T、P、v1、v2、n，分别表示：
//  T：最大追击时间限制（单位：时间）。
//  P：警犬与鹅战士的初始距离（单位：距离）。
//  v1：警犬的速度（单位：距离/时间）。
//  v2：鹅战士的速度（单位：距离/时间）。
//  n：障碍的数量（可以为0）。
//  接下来的 n 行：每行2个整数 L 和 K，表示障碍的位置和类型：
//  L：障碍的位置（单位：距离）。
//  K：障碍的类型（1=小障碍，2=中障碍，3=大障碍）。(小障碍停1s，中障碍听2s，大障碍停5s)
// Output
// 如果警犬在时间 T 内追上鹅战士，输出 "nice try!"。
// 如果超时（时间超过 T 仍未追上），输出 "路边一条"。

// Samples
// input
// 10 10 5 3 0
// output
// nice try!
// input
// 10 100 5 3 1
// 5 1
// output
// 路边一条

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 注意此代码思路不是完全正确，有很多漏洞，但是恰好AC了哈哈，所以参考价值有限
int main()
{
    double T, P, v1, v2, n;
    cin >> T >> P >> v1 >> v2 >> n;

    if (v1 <= v2 && P != 0)
    {
        cout << "路边一条" << endl;
        return 0;
    }
    if (P == 0)
    {
        cout << "nice try!" << endl;
        return 0;
    }

    vector<double> blockP;
    vector<double> blockT;
    // 我使用通过障碍的位置来把追击过程分段讨论
    // 所以障碍数据首部加上0，以保证后续算法可以进行
    blockP.push_back(0);
    blockT.push_back(0);
    for (int i = 0; i < n; i++)
    {
        // 保存障碍位置和时间数据
        int a, b;
        cin >> a >> b;
        blockP.push_back(a);
        switch (b)
        {
        case 1:
            blockT.push_back(1);
            break;
        case 2:
            blockT.push_back(2);
            break;
        case 3:
            blockT.push_back(5);
            break;
        }
    }
    // 把障碍物按照从近到远的距离排序
    for (int i = 0; i < n + 1 - 1; i++)
    {
        for (int j = 0; j < n + 1 - i - 1; j++)
        {
            if (blockP[j] > blockP[j + 1])
            {
                swap(blockP[j], blockP[j + 1]);
                swap(blockT[j], blockT[j + 1]);
            }
        }
    }

    // 没有障碍物 普通情况 直接算规定时间谁跑得远
    // 警远肯定追上了
    if (n == 0)
    {
        if (v1 * T >= v2 * T + P)
        {
            cout << "nice try!" << endl;
            return 0;
        }
        else
        {
            cout << "路边一条" << endl;
            return 0;
        }
    }
    // 有障碍物的时候
    double allTime = 0;
    for (int i = 0; i < n; i++)
    {
        // 看两个障碍物之间追击时间和距离
        double deltaDist = blockP[i + 1] - blockP[i];
        double deltaTime = deltaDist / v1;
        allTime += deltaTime;
        // 追击时间已经超时了，就回退这一步，把上一步剩下的时间当作追击时间
        // 然后按照 普通的追击规则 算
        if (allTime >= T)
        {
            T = T - (allTime - deltaTime);
            if (v1 * T >= v2 * T + P)
            {
                cout << "nice try!" << endl;
                return 0;
            }
            else
            {
                cout << "路边一条" << endl;
                return 0;
            }
        }
        double newP = deltaTime * v2 + P; // 更新鹅的位置
        if (newP <= blockP[i + 1])
        // 警跑到障碍的位置了，发现鹅还在后面就是追到了
        {
            cout << "nice try!" << endl;
            return 0;
        }
        // 鹅还是在远处，那警只能先在这个障碍物等待
        // 同时更新一下 时间计数和鹅的位置
        newP += blockT[i + 1] * v2;
        allTime += blockT[i + 1];
        P = newP;
    }
    // 障碍过完了，时间还有剩余的情况
    T = T - allTime;
    if (T <= 0)
    {
        cout << "路边一条" << endl;
        return 0;
    }
    if (v1 * T + blockP[n] >= v2 * T + P)
    // 还是看谁在剩余时间之后跑得远了
    {
        cout << "nice try!" << endl;
        return 0;
    }
    else
    {
        cout << "路边一条" << endl;
        return 0;
    }
}

// AI说我的代码有根本性的逻辑错误，我也确实没有完全通过AI给我的大量测试案例
// 本来绝望了想看看AI写的，最后赌一把把自己改过的代码又交了一下，竟然过了，笑死我了。
// 你就说过没过吧！！！