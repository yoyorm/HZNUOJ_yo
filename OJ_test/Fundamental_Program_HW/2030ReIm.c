// 【C系列7.5】结构-5 叫姐姐 AC
// Description
// 最近loy觉得数学太简单了，竟对老师布置的复数四则运算不屑一顾，就把作业扔给你去做了。
// 所以，辛苦你啦。（此题另一种解法：找到loy本人让她写）
// Input
// 多组输入。
// 每组四个浮点数，分别为第一个复数的实部、虚部，第二个数的实部、虚部。
// Output
// 输出四则运算的结果，注意输出格式
// （输出精确到小数后一位。若实部和虚部都是0，输出0.0。等号前不需要考虑0）。
// Samples

// input
// 2.5 3.6 5.2 -1.3
// 3.6 4.1 9.4 5.1
// -1.1 5.6 6.7 3
// output
// (2.5+3.6i) + (5.2-1.3i) = 7.7+2.3i
// (2.5+3.6i) - (5.2-1.3i) = -2.7+4.9i
// (2.5+3.6i) * (5.2-1.3i) = 17.7+15.5i
// (2.5+3.6i) / (5.2-1.3i) = 0.3+0.8i
// (3.6+4.1i) + (9.4+5.1i) = 13.0+9.2i
// (3.6+4.1i) - (9.4+5.1i) = -5.8-1.0i
// (3.6+4.1i) * (9.4+5.1i) = 12.9+56.9i
// (3.6+4.1i) / (9.4+5.1i) = 0.5+0.2i
// (-1.1+5.6i) + (6.7+3.0i) = 5.6+8.6i
// (-1.1+5.6i) - (6.7+3.0i) = -7.8+2.6i
// (-1.1+5.6i) * (6.7+3.0i) = -24.2+34.2i
// (-1.1+5.6i) / (6.7+3.0i) = 0.2+0.8i
// Show after trying 4 times:
// input
// 1.1 1.1 -1.1 -1.1
// output
// (1.1+1.1i) + (-1.1-1.1i) = 0.0
// (1.1+1.1i) - (-1.1-1.1i) = 2.2+2.2i
// (1.1+1.1i) * (-1.1-1.1i) = -2.4i
// (1.1+1.1i) / (-1.1-1.1i) = -1.0

#include <stdio.h>
struct num
{
    double re;
    double im;
};
void addit(const struct num *x, const struct num *y);
void minus(const struct num *x, const struct num *y);
void multiply(const struct num *x, const struct num *y);
void divide(const struct num *x, const struct num *y);
void printit(const struct num *x, const struct num *y, const struct num *z, const char s);

int main()
{
    struct num x, y;
    while (scanf("%lf %lf", &x.re, &x.im) != EOF && scanf("%lf %lf", &y.re, &y.im) != EOF)
    {
        addit(&x, &y);
        minus(&x, &y);
        multiply(&x, &y);
        divide(&x, &y);
    }
}

void addit(const struct num *x, const struct num *y)
{
    struct num sum;
    sum.re = x->re + y->re;
    sum.im = x->im + y->im;
    printit(x, y, &sum, '+');
}

void minus(const struct num *x, const struct num *y)
{
    struct num min;
    min.re = x->re - y->re;
    min.im = x->im - y->im;
    printit(x, y, &min, '-');
}

void multiply(const struct num *x, const struct num *y)
{
    struct num mul;
    mul.re = x->re * y->re - x->im * y->im;
    mul.im = x->re * y->im + x->im * y->re;
    printit(x, y, &mul, '*');
};

void divide(const struct num *x, const struct num *y)
{
    struct num div;
    div.re = (x->re * y->re + x->im * y->im) / (y->re * y->re + y->im * y->im);
    div.im = (x->im * y->re - x->re * y->im) / (y->re * y->re + y->im * y->im);
    printit(x, y, &div, '/');
}
void printit(const struct num *x, const struct num *y, const struct num *z, const char s)
{
    if (x->im >= 0)
        printf("(%.1lf+%.1lfi)", x->re, x->im);
    else
        printf("(%.1lf%.1lfi)", x->re, x->im);
    printf(" %c ", s);
    if (y->im >= 0)
        printf("(%.1lf+%.1lfi)", y->re, y->im);
    else
        printf("(%.1lf%.1lfi)", y->re, y->im);
    printf(" = ");
    if (z->im == 0 && z->re == 0)
    {
        printf("0.0\n");
        return;
    }
    if (z->re == 0)
    {
        printf("%.1lfi\n", z->im);
    }
    if (z->re != 0)
    {
        if (z->im < 0)
        {
            printf("%.1lf%.1lfi\n", z->re, z->im);
        }
        else if (z->im > 0)
            printf("%.1lf+%.1lfi\n", z->re, z->im);
        else
            printf("%.1lf\n", z->re);
        return;
    }
}
