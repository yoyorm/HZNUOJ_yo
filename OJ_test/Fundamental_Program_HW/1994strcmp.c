// Description
// Alex想要写一函数，实现两个字符串的比较。即自己写一个strcmp函数，函数原型为：
//  int stremp(char *p1,char *p2)
// 设p1指向字符串s1，p2指向字符串s2。要求：当s1=s2时，返回值为0。当s1不等于s2时，返回它们二者的第一个不同字符的ASCII码差值（如“BOY”与“BAD”，第二字母不同，“O”与“A”之差为79-65=14）；
// 如果s1>s2，则输出正值；如果s1<s2，则输出负值。
// Input
// 输入含多组测试数据，每组测试数据为两个只包含字母的字符串s1、s2，每个字符串长度不超过100，s1与s2字符串长度相等。
// Output
//  当s1=s2时，输出0。当s1不等于s2时，输出它们二者的第一个不同字符的ASCII码差值。

#include <stdio.h>
int stremp(char *p1, char *p2)
{
    while (*p1 == *p2 && *p1 && *p2)
    {
        p1++;
        p2++;
    }
    return *p1 - *p2;
}

int main()
{
    char s1[101], s2[101];
    while (scanf("%s %s", s1, s2) != EOF)
    {
        printf("%d\n", stremp(s1, s2));
    }
    return 0;
}