// Description
// 得知Bob要去菜鸟驿站，Alice让他帮忙拿下快递，并把自己在那里的快递的取货码都发给了他，Bob在排队拿快递的时候对他究竟每家快递公司要各拿多少个快递感到好奇，请你帮他计算出答案。已知菜鸟驿站的快递取货码编号为A-B-C(A为货架数字，B为货架层数，C为四位验证码)，对于A来说1-25为韵达快递，26-55为圆通快递，56-69为EMS快递，70-103为百世快递，104-125为顺丰快递，200-230为申通快递，231-250为中通快递，其他数字为其他快递。
// Input
// 输入的第一行为n(1<=n<=1000),表示Alice收到的快递个数。
// 接下来的n行，是每个快递的取货码编号A-B-C,(1<=A<=300, 1<=B<=5, 1000<=C<=9999)
// Output
// 按照韵达，圆通，EMS，百世，顺丰，申通，中通，其他快递公司的顺序输出每家快递公司的快递个数，每两个数字之间有一个空格
// Samples
// input
// 3
// 110-2-5468
// 35-5-4875
// 84-1-6021
// output
// 0 1 0 1 1 0 0 0

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int brand[8] = {};
    int *s = new int[n];
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> s[i];
        getline(cin, temp);
        //反正后面的其他数据都是没有用的，干脆不要了哈哈
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 1 && s[i] <= 25)
        {
            brand[0]++;
        }
        else if (s[i] >= 26 && s[i] <= 55)
        {
            brand[1]++;
        }
        else if (s[i] >= 56 && s[i] <= 69)
        {
            brand[2]++;
        }
        else if (s[i] >= 70 && s[i] <= 103)
        {
            brand[3]++;
        }
        else if (s[i] >= 104 && s[i] <= 125)
        {
            brand[4]++;
        }
        else if (s[i] >= 200 && s[i] <= 230)
        {
            brand[5]++;
        }
        else if (s[i] >= 231 && s[i] <= 250)
        {
            brand[6]++;
        }
        else
        {
            brand[7]++;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (i != 7)
            cout << brand[i] << " ";
        else
        {
            cout << brand[i];
        }
    }

    delete[] s;
}