// 二进制加法 AC
// Description
// 计算机使用的是二进制，和十进制不同的是：二进制运算“逢二进一”。下面举一个二进制加法的运算实例:

//    11101          
// +    110          
// ------------       
//  100011          
// 1所在的位置：
// 6、2、1          
// 你的任务是：对于任意的两个正的二进制数，求它们和中“1”所在的位置。
// Input
// 有多组测试数据，每组测试数据共两行：
// 第一行：二进制的加数A，总长度<=200。
// 第二行：二进制的加数B，总长度<=200。
// Output
// 输出二进制数A+B中“1”所在的位置，位置排序为从左到右：
//N、N-1、N-2...1，数据之间用空格分隔，行末没有多余的空格。


#include <iostream>
#include <cstring>
using namespace std;
void reverse(char *s, short len);
void addit(char *a, char *b, int *sum, short lenA, short lenB);
int main()
{
    char a[201] = {}, b[201] = {};
    while (scanf("%s %s", a, b) == 2)
    {
        short A = strlen(a), B = strlen(b);
        reverse(a, A);
        reverse(b, B);
        int sum[201] = {};
        addit(a, b, sum,A,B);
        int hasprint = 0;
        for (short i = 200; i >= 0; i--)
        {
            if (sum[i] != 0)
            {
                if (hasprint == 0)
                {
                    cout << i + 1;
                    hasprint = 1;
                }
                else
                {
                    cout << " " << i + 1;
                }
            }
        }
        cout << endl;
    }
}

void reverse(char *s, short len)
{
    for (short i = 0; i < len / 2; i++)
    {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}
void addit(char *a, char *b, int *sum, short lenA, short lenB)
{
    for (short i = 0; i < 201; i++)
    {
        sum[i] = ((i < lenA) ? a[i] - '0' : 0) + ((i < lenB) ? b[i] - '0' : 0);
    }
    for (short i = 0; i < 200; i++)
    {
        if (sum[i] > 1)
        {
            sum[i + 1] += sum[i] / 2;
            sum[i] = sum[i] % 2;
        }
    }
}
