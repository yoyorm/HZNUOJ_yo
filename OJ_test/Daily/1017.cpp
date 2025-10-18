// Description
// 输入一个整数N，再输入一个整数M，查找整数M在N中第一次出现的位置。
// Input
// 输入两个整数N和M，满足1<=N,M<=2^32，且N>=M。
// 需要说明的是，比赛中的测试数据都是多组的，在没有明确说明测试多少次的情况下，请都用上while(scanf()!=EOF)或者while(~scanf())，以表明直到输入结束时才结束程序。若无此循环，你的程序可能将在一次测试后就结束，这样会导致Wrong Answer。
// Output
// 输出M在N中出现的起始位置（从0开始算），如果不存在，则输出-1，若存在，则找出对应的位置。
// Samples
// input
// 1123445 234
// 1234567 4587
// 1239 1239
// output
// 2
// -1
// 0

#include <iostream>
#include <cstring>
using namespace std;
int findit(char *data, char *test);
int main()
{
    char data[10], test[10];
    while (cin >> data && cin >> test)
    {
        cout << findit(data, test) << endl;
    }

    return 0;
}

int findit(char *data, char *test)
{
    for (int i = 0; i < 10; i++)
    {
        if (strncmp(data + i, test, strlen(test)) == 0)
        {
            return i;
        }
    }
    return -1;
}
