// Description

// 用递归的方法画一个九九乘法表。一个式子内没有空格，式子间有一个空格，每行最后一个式子后没有空格。前4行是这样的：
// 1*1=1
// 1*2=2 2*2=4
// 1*3=3 2*3=6 3*3=9
// 1*4=4 2*4=8 3*4=12 4*4=16

// （主函数代码部分已经写好，只需写函数部分，如果提交的不是c语言则需要提交全部代码）


#include<stdio.h>
#include<math.h>
void happy(int row);
int main() {
    happy(9);
    return 0;
}

void happy(int row)
{
    if(row==18)
    {
    return;
    }
    int i =row-8;
    for(int k=1;k<=i;k++)
        {
            if(k<i)
                printf("%d*%d=%d ",k,i,i*k);
            else
                printf("%d*%d=%d",k,i,i*k);
        }
    printf("\n");
    happy(row+1);
}