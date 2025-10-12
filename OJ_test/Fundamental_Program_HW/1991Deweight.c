// Description
// Alex在朋友们都去生猴子了的日子里，日复一日、年复一年地敲代码，终于，在经年累月的摧残下，她的手指变得不那么利索了.
// 比如“how are you”她会哆嗦着打成“hhoow areee youuu”.
// 如果两个及以上的字母同时出现，则被认为是多打出来的，她想请你帮忙做的事情就是正确翻译出她想要表达的语句。
// Input
// 输入多组数据。
// 每组一行包含空格的字符串，长度不超过10000。

#include <stdio.h>
#include <string.h>
int main()
{
    char line[10001];
    line[10000] = '\0';
    char temp;
    int firstword = 1;
    while (fgets(line, sizeof(line), stdin))
    //fgets 会读取换行符
    {
        int length = strlen(line);
        for (int i = 0; i < length; i++)
        {
            if (line[i] != line[i - 1])
            {
                printf("%c", line[i]);
            }
        }
    }
}
