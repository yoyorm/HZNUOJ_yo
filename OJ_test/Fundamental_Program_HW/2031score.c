// 【C系列7.6】结构-6 无题 AC 2031
// Description
// 给你n个学生的3门考试的成绩，要求输出这三门课每门课中成绩最好的学生姓名和他在这三门课的成绩，
// 然后按平均成绩从高到低输出所有学生信息，接着输出平均分高于80分的学生信息和其平均成绩。
// Input
// 第一行为一个正整数n（n>=3），其后跟n行，每一行为一个学生的信息，包含学生姓名（最多9个字符），和学生三门课的成绩。
// Output
// 前3行位这三门课中成绩最好的学生姓名和这三门课的成绩，
// 其后n行按平均成绩从高到低输出学生信息，接下来几行为平均分高于80分的学生信息和其平均成绩。
// 其中学生信息就是每行输入的信息。（每行数据间以逗号分隔，每块内容间输出一个回车，输出保留两位小数。）
// Samples
// input
// 5
// zz 100 100 100
// loy 90 80 70
// yl 85 78.5 90
// mwy 59 59.9 59.99
// cjc 0 0 0
// output
// zz,100.00,100.00,100.00
// zz,100.00,100.00,100.00
// zz,100.00,100.00,100.00

// zz,100.00,100.00,100.00
// yl,85.00,78.50,90.00
// loy,90.00,80.00,70.00
// mwy,59.00,59.90,59.99
// cjc,0.00,0.00,0.00

// zz,100.00,100.00,100.00,100.00
// yl,85.00,78.50,90.00,84.50

#include <stdio.h>
#include <stdlib.h>
struct stu
{
    char name[10];
    double score1;
    double score2;
    double score3;
    double ave;
};
void sortscore(struct stu *stu, int num);
void sortave(struct stu *stu, int num);

int main()
{
    int num;
    scanf("%d", &num);
    struct stu *stu = (struct stu *)malloc(num * sizeof(struct stu));
    for (int i = 0; i < num; i++)
    {
        scanf("%s %lf %lf %lf", &stu[i].name, &stu[i].score1, &stu[i].score2, &stu[i].score3);
        stu[i].ave = (stu[i].score1 + stu[i].score2 + stu[i].score3) / 3;
    }
    sortscore(stu, num);
    printf("\n");
    sortave(stu, num);
}
void sortscore(struct stu *stu, int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            if (stu[j].score1 < stu[j + 1].score1)
            {
                struct stu temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    printf("%s,%.2lf,%.2lf,%.2lf\n", stu[0].name, stu[0].score1, stu[0].score2, stu[0].score3);
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            if (stu[j].score2 < stu[j + 1].score2)
            {
                struct stu temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    printf("%s,%.2lf,%.2lf,%.2lf\n", stu[0].name, stu[0].score1, stu[0].score2, stu[0].score3);
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            if (stu[j].score3 < stu[j + 1].score3)
            {
                struct stu temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    printf("%s,%.2lf,%.2lf,%.2lf\n", stu[0].name, stu[0].score1, stu[0].score2, stu[0].score3);
}
void sortave(struct stu *stu, int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            if (stu[j].ave < stu[j + 1].ave)
            {
                struct stu temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        printf("%s,%.2lf,%.2lf,%.2lf\n", stu[i].name, stu[i].score1, stu[i].score2, stu[i].score3);
    }
    printf("\n");
    for (int i = 0; i < num; i++)
    {
        if (stu[i].ave > 80)
            printf("%s,%.2lf,%.2lf,%.2lf,%.2lf\n", stu[i].name, stu[i].score1, stu[i].score2, stu[i].score3, stu[i].ave);
    }
}