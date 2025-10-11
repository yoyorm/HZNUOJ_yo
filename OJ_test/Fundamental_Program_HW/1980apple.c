// cyn小朋友所在的幼儿园今天上午的点心是苹果，但是mwy老师分到最后发现多了两个苹果，
//于是他决定用一种方法找出一位位幸运儿。

// n个小朋友围成一圈，编号从1-n，第一个人从1数起，数到7的那个人就被淘汰出局，
//接下来的人又从1数起，数到7再次被淘汰（如果人数不满7个，则循环着数）……最后剩下的一个人就是赢家（主函数已经给出）

#include<stdio.h>
#include<stdlib.h>
int jos(int n);
int main()
{
    int n,s,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        s = jos(n);
        printf("%d ", s);
    }
    return 0;
}

int jos(int n)
{
    int* data =(int*)malloc(sizeof(int)*n);
    int cont=0;
    for(int k=0;k<n;k++)//初始化数组
    {
        data[k]=1;
    }
    int finish=0;
    while(finish==0)
    {
        int add=0;
        for(int i=0;i<n;i++)
        {
            add+=data[i];
        }
        if(add==1)//判断是否只剩一个人
        {
            finish=1;
            for(int k=0;k<n;k++)
            {
                if(data[k]==1)
                {
                    free(data);
                    return k+1;
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            if(data[j]==1)
            {
                cont++;
                if(cont==7)
                {
                    data[j]=0;
                    cont=0;
                }
            }
        }
    }
}