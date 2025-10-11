// Description

// 编写一个函数，该函数用迭代法求平方根。求平方根的迭代公式为：
// 其中a 是需要求平方根的数。（主函数代码部分已经写好，只需写函数部分，如果提交的不是c语言则需要提交全部代码）
// #include<stdio.h>
// #include<math.h>

// double happy(double a);
// double a;

// int main() {
//     while (scanf("%lf", &a) != EOF) {
//         printf("%.6lf ", happy(a));
//     }
//     return 0;
// }

// Input

// 输入实数a。
// Output
// 输出a的平方根。答案精确到10-6.
// Samples
// input 
// 8
// output 
// 2.828427


#include<stdio.h>
#include<math.h>

double happy(double a);
double a;

int main() {
    while (scanf("%lf", &a) != EOF) {
        printf("%.6lf ", happy(a));
    }
    return 0;
}

double happy(double a)
{
    double temp=a;
    if(a==0)
    {
    return 0;
    }
    for(int i=0;i<20;i++)
    {
        temp=(temp+a/temp)/2;
    }
    return temp;
}
