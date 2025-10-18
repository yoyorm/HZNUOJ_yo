// Description
// 字符串的输入输出处理。
// Input
// 第一行是一个正整数N，最大为100。之后是多行字符串（行数大于N）， 每一行字符串可能含有空格，字符数不超过1000。
// Output
// 先将输入中的前N行字符串（可能含有空格）原样输出，再将余下的字符串（不含有空格）以空格或回车分割依次按行输出。每行输出之间输出一个空行。
// Samples
// input
// 2
// hsacm.cn HZNU
// A C M
// H Z N Uer
// output
// hsacm.cn HZNU
//
// A C M
//
// H
//
// Z
//
// N
//
// Uer
//

#include <iostream>
#include <cstring>
using namespace std;
void printData(string data);
int main()
{
    int T;
    cin >> T;
    getchar();
    string data;
    while (getline(cin, data))
    {
        if (T > 0)
        {
            cout << data << endl
                 << endl;
            T--;
        }
        else
        {
            printData(data);
        }
    }
}

void printData(string data)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] != ' ')
        {
            cout << data[i];
        }
        else
        {
            cout << endl
                 << endl;
        }
    }
    if (data[data.size() - 1] != ' ')
    {
        cout << endl
             << endl;
    }
}