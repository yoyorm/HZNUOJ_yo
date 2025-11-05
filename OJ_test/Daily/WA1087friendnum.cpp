// #include <cstdio>
// #include <vector>
// using namespace std;

// const int MAX = 5000000;
// int numbers[MAX] = {};
// vector<unsigned short> list(MAX, 0);
// int main()
// {
//     for (int i = 1; i < MAX; i++)
//     {
//         for (int j = i * 2; j < MAX; j += i)
//         {
//             numbers[j] += i;
//         }
//     }
//     for (int i = 2; i < MAX; i++)
//     {
//         int j = numbers[i];
//         if (j > i && j < MAX && numbers[j] == i)
//         {
//             list[i] = 1;
//         }
//     }
//     for (int i = 1; i < MAX; i++)
//     {
//         list[i] += list[i - 1];
//     }
//     int a, b;
//     while (scanf("%d %d", &a, &b) != EOF)
//     {
//         if (a == 1)
//         {
//             printf("%d\n", list[b]);
//         }
//         else
//             printf("%d\n", list[b] - list[a - 1]);
//     }
// }
#include <cstdio>
#include <vector>
using namespace std;

const int MAXV = 5000000;
int d[MAXV + 1];                    // 真因子和
vector<unsigned short> pc(MAXV + 1); // pc[i] = [1,i] 里完整落在[1,i]中的亲密数对数量

int main() {
    /* 1. 倍数法求真因子和 */
    for (int i = 1; i <= MAXV; ++i)
        for (int j = i * 2; j <= MAXV; j += i)
            d[j] += i;

    /* 2. 在较小端标记 */
    for (int i = 2; i <= MAXV; ++i) {
        int j = d[i];
        if (j > i && j <= MAXV && d[j] == i)
            pc[i] = 1;          // 在较小端记1
    }

    /* 3. 前缀和 */
    for (int i = 1; i <= MAXV; ++i)
        pc[i] += pc[i - 1];

    /* 4. 查询 */
    int a, b;
    while (scanf("%d %d", &a, &b) == 2)
        printf("%d\n", pc[b] - pc[a - 1]);
    return 0;
}