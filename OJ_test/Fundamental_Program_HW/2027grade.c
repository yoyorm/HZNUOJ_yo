// Description
// 期末考试刚刚结束，ACM队的同学们终于暂时摆脱了烦人的学业了。
// 这不，现在他们为了找事做，决定对他们xx课程的分数评一下级，来看看自己是有多么的“优秀”。
// Input
//  输入第一行为x和y，接下来有x(0<x<20)行。
// 对于接下来x行的每一行，有三个参数n,m,s，n整数是该同学的准考证号，m字符串是该同学的名字，s数字是该同学的成绩。其中0<n<10^9, 0<=s<100, m长度不超过15。
// 再接下来有y(0<y<20)行，每行有一个数字a,代表所需要查询的学生的准考证号(一个号码可能被查询多次)。
// Output
//  输出被查询的学生的准考证号的等级。等级评定如下：
// 90<=x<=100：A；
// 80<=x<90：B；
// 70<=x<80：C；
// 60<=x<70：OK；
// x<60：ARE YOU PIG?
// Samples
// input
// 5 3
// 1000001 szy 100
// 1000002 wxa 98
// 1000003 zz 95
// 1000004 yl 80
// 1000005 loy 59
// 1000003
// 1000001
// 1000005
// output
// A
// A
// ARE YOU PIG?

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    long long ID;
    char name[100];
    short score;
} student;
void judge(student *students);
int main()
{
    student students[20];
    int create_num;
    int find_num;
    scanf("%d %d", &create_num, &find_num);
    for (int i = 0; i < create_num; i++)
    {
        scanf("%lld %s %d", &students[i].ID, students[i].name, &students[i].score);
    }
    long long *find_ID = (long long *)malloc(find_num * sizeof(long long));
    for (int i = 0; i < find_num; i++)
    {
        scanf("%lld", &find_ID[i]);
    }
    for (int i = 0; i < find_num; i++)
    {
        for (int j = 0; j < create_num; j++)
        {
            if (students[j].ID == find_ID[i])
            {
                judge(&students[j]);
                break;
            }
        }
    }
    return 0;
}

void judge(student *students)
{
    if (students->score >= 90)
    {
        printf("A\n");
    }
    else if (students->score >= 80)
    {
        printf("B\n");
    }
    else if (students->score >= 70)
    {
        printf("C\n");
    }
    else if (students->score >= 60)
    {
        printf("OK\n");
    }
    else
    {
        printf("ARE YOU PIG?\n");
    }
}