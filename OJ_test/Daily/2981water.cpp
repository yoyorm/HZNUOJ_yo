// 水题
// Description
// 你拥有一个无限高度的水池，他的底面长和宽是A,B，初始我们向水池中注入H深的水，现在我们将一个底面为长a，宽b高为h的铁制长方体(密封不透水)以底面朝下垂直放入水池中，求问水池水位变为多少。（柱体不会浮起来）
// Input
// 第一行输入t（0<t<=10）组样例
// 每组样例分两行第一行A,B,H 表示水池底面长宽和水位高度
// 第二行输入a，b，h标示长方体体底面长宽和高度
// 0<B,A<100,0<b,a<min(A,B),0<h<1000,0<H<1000
// Output
// 输出铁柱体放入后的水位高度，保留两位小数
// Samples
// input
// 1
// 6 8 7
// 4 4 6
// output
// 9.00

#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        double x, y, h; // 水大小
        cin >> x >> y >> h;

        double a, b, c; // 方块大小
        cin >> a >> b >> c;
        double V = x * y * h;
        double C = c;
        double S = x * y;
        double s = a * b;
        double dH = -1;
        while (C > 0 && dH > 0.00001 || dH == -1)
        //循环计算一直到水面上升的量很小了就结束
        {
            //把放入过程拆分成，放入和上涨两个过程
            double dC;
            if (dH == -1)
            {
                dH = h;
                //初始化一下dh
            }
            if (C > dH)
            {

                dC = dH;
                //不能完全放进去
            }
            else
            {
                //可以完全放进去，就直接算完增加量结束
                dC = C;
                V += dC * s;
                break;
            }
            C -= dC;
            V += dC * s;
            dH = dC * s / S;
            //没完全放进去就要算上涨，然后继续计算“之前漏在水外面的部分”放入的效果
        }
        h = V / S;
        printf("%.2lf\n", h);
    }
}
