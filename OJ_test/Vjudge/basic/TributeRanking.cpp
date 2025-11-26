// https://www.luogu.com.cn/problem/P1786

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct person
{
    string name;
    string oldpositon;
    long long score;
    int grade;
    int pos;
};
enum state
{
    BangZhong,
    JingYing,
    TangZhu,
    ZhangLao,
    HuFa,
    FuBangZhu,
    BangZhu
};
state getValue(const string &position)
{
    if (position == "BangZhong")
        return BangZhong;
    if (position == "JingYing")
        return JingYing;
    if (position == "TangZhu")
        return TangZhu;
    if (position == "ZhangLao")
        return ZhangLao;
    if (position == "HuFa")
        return HuFa;
    if (position == "FuBangZhu")
        return FuBangZhu;
    if (position == "BangZhu")
        return BangZhu;
    return BangZhong;
} // 转换字符串为枚举值
int main()
{
    int num;
    cin >> num;
    vector<person> p(num);
    for (int i = 0; i < num; i++)
    {
        cin >> p[i].name >> p[i].oldpositon >> p[i].score >> p[i].grade;
        p[i].pos = i + 1;
    }
    sort(p.begin(), p.end(), [](person a, person b) // 先按照分数和输入位置排序
         { 
        if(a.score != b.score)
        return a.score > b.score;
        else
        return a.pos<b.pos; });

    int count = 0;
    for (int i = 0; i < num; i++) // 重新分配职位
    {
        if (p[i].oldpositon != "BangZhu" && p[i].oldpositon != "FuBangZhu")
        {
            if (count < 2)
            {
                p[i].oldpositon = "HuFa";
            }
            else if (count < 6)
            {
                p[i].oldpositon = "ZhangLao";
            }
            else if (count < 13)
            {
                p[i].oldpositon = "TangZhu";
            }
            else if (count < 38)
            {
                p[i].oldpositon = "JingYing";
            }
            else
            {
                p[i].oldpositon = "BangZhong";
            }
            count++;
        }
    }
    sort(p.begin(), p.end(), [](person a, person b) // 再按照职位和等级排序
         {   if(a.oldpositon != b.oldpositon)
        return  getValue(a.oldpositon)>getValue(b.oldpositon) ;
        else if(a.grade != b.grade)
        return a.grade>b.grade;
        else
        return a.pos<b.pos; });

    for (int i = 0; i < num; i++)
    {
        cout << p[i].name << " " << p[i].oldpositon << " " << p[i].grade << endl;
    }
}
