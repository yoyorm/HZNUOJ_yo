// 断桥残雪 AC

// Description
// 断桥残雪是杭州著名的十景之一，同样也是游客们来杭州游玩只是必经的景点，所以这桥上的人头密集程度自是不可想象的。
// 今天的kk同样也是那样的努力。通过对acm的不懈努力。他终于成功参加了杭州西湖第一届acm湖上程序设计大赛。但是比赛还有9小时才开始，kk觉得好无聊，于是就对旁边真·全是人头觉得要踏的断桥研究了起来。
// 这么多的人每个时间段断桥上的人流又是怎样的呢？
// 但是kk每次数数的时候，眼里只会有一种人，可能是男生，女生也可能是一种宠物。
// 当然kk也不可能注意力这么集中得数数，总会有东西打断他的数数，所以，kk每小时得到数据会有很多组。
// 但是有一点很神奇，kk绝对不会漏数任何一个生物。
// 但是每个物种每个小时到底经过了多少呢？
// kk为难了，他不知道，他只会数数。于是他用他水汪汪的眼睛看向了他的队友金老师，金老师不屑地摇摇头，把任务扔给了你。(看不懂可以直接看输入输出和样例解释)

// Input
// 第一行有一个整数T（T<100)；
// 接下来的T行每行都包含三个32位整数，n(0<n<=24)，m(m=1,2,3)，h(h<100)；
// 其中n代表一天中的第n个小时，m代表第m个物种：1-男生，2-女生，3-宠物；h代表kk数出的物种的数量。
// 然后很多行询问，每行包含两个整数x，y。输入以0 0结束。
// x是一天中的第x个小时，y代表想要知道的物种。

// Output
// 我们需要得出第x小时的时候总共经过了多少y物种的生物。
// 输入以0 0结束。
// Samples
// input
// 4
// 2 3 2
// 1 2 4
// 2 3 9
// 5 1 111
// 1 3
// 5 1
// 2 3
// 0 0
// output
// 0
// 111
// 11

// Hint
// 第一行是一个T=4；
// 接下来的四行表示，在第二个小时内经过了2只宠物，在第一个小时内经过了4个女生，在第二个小时又经过了9只宠物，在第五个小时经过了111个男生。
// 紧接着是询问，在第一个小时里并没有宠物经过，所以输出0，第五个小时内经过了111个男生，所以输出111，第二个小时里经过了2+9=11只宠物，所以输出11.
// 遇见0 0，输入结束。

#include <iostream>
using namespace std;

struct hour
{
    int h = -1;
    int man = 0;
    int women = 0;
    int pet = 0;
};

void input(hour *h, int T);
void serach(hour *h, int T);
int main()
{
    int T, count = 0;
    cin >> T;
    hour *h = new hour[T];
    for (int i = 0; i < T; i++)
    {
        input(h, T);
    }
    // for (int i = 0; i < T; i++)
    // {
    //     cout << h[i].h << " " << h[i].man << " " << h[i].women << " " << h[i].pet << endl;
    // }
    serach(h, T);
}

void input(hour *h, int T)
{
    int hour;
    int pos;
    cin >> hour;
    for (int i = 0; i < T; i++)
    {
        if (h[0].h == -1 && i == 0)
        //第一个小时，特殊处理
        {
            pos = 0;
            h[pos].h = hour;
            break;
        }

        if (hour == h[i].h)
        //先找有没有已经存过的相同时间，有就直接在里面存取
        {
            pos = i;
            break;
        }
        else if (h[i].h == -1)
        //没有就在未存储的地方新建一个
        {
            h[i].h = hour;
            pos = i;
            break;
        }
        else
        {
            continue;
        }
    }
    int kind;
    cin >> kind;
    int num;
    cin >> num;
    switch (kind)
    //根据数据往里面存数据
    {
    case 1:
        h[pos].man += num;
        break;
    case 2:
        h[pos].women += num;
        break;
    case 3:
        h[pos].pet += num;
        break;
    }
}

void serach(hour *h, int T)
{
    int hour, target;
    while (cin >> hour >> target && (hour != 0 && target != 0))
    {
        bool out = false;
        for (int i = 0; i < T; i++)
        //遍历寻找对应的时间
        {
            if (hour == h[i].h)
            {
                switch (target)
                {
                case 1:
                    cout << h[i].man << endl;
                    out = true;
                    break;
                case 2:
                    cout << h[i].women << endl;
                    out = true;
                    break;
                case 3:
                    cout << h[i].pet << endl;
                    out = true;
                }
                break;
            }
        }
        if (!out)
        //如果没有找到对应时间就输出0
            cout << "0" << endl;
    }
}