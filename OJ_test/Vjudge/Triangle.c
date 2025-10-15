// Description
// 给出三条线段
// a,b,c 的长度，均是不大于
// 10000
// 10000 的正整数。打算把这三条线段拼成一个三角形，它可以是什么三角形呢？

// 如果三条线段不能组成一个三角形，输出Not triangle；
// 如果是直角三角形，输出Right triangle；
// 如果是锐角三角形，输出Acute triangle；
// 如果是钝角三角形，输出Obtuse triangle；
// 如果是等腰三角形，输出Isosceles triangle；
// 如果是等边三角形，输出Equilateral triangle。
// 如果这个三角形符合以上多个条件，请按以上顺序分别输出，并用换行符隔开。

#include <stdio.h>
void sort(int data[]);
int isTriangle(int data[]);
void isEquilateral(int data[]);
void whatTriangle(int data[]);
int main()
{
    int data[3];
    scanf("%d%d%d", &data[0], &data[1], &data[2]);
    sort(data);
    if (isTriangle(data))
    {
        whatTriangle(data);
        isEquilateral(data);
    }
}

void sort(int data[])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i; j++)
        {
            int temp;
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int isTriangle(int data[])
{
    if (data[0] + data[1] > data[2])
    {
        return 1;
    }
    else
    {
        printf("Not triangle");
        return 0;
    }
}
void isEquilateral(int data[])
{
    if (data[0] == data[1] || data[1] == data[2] || data[0] == data[2])
    {
        printf("Isosceles triangle\n");
    }
    if (data[0] == data[1] && data[1] == data[2])
    {
        printf("Equilateral triangle\n");
    }
}
void whatTriangle(int data[])
{
    float cos;
    cos = ((float)data[0] * data[0] + data[1] * data[1] - data[2] * data[2]) / (2 * data[0] * data[1]);
    if (cos > 0)
    {
        printf("Acute triangle\n");
    }
    else if (cos == 0)
    {
        printf("Right triangle\n");
    }
    else
    {
        printf("Obtuse triangle\n");
    }
}
