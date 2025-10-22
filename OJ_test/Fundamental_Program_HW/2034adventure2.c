// 【C系列7.9】结构-9：女神历险记2 AC 2034

// Description
// 经过之前的经历，loy已经成功的破译出了所有的密码。她组建了一直探墓小分队，向着她算出来的最终的目标——xx墓出发。过了几个月，他们终于到达了目的地。财富就在眼前，然而却被入门的机关给卡住了。经过一段时间的观察，loy发现了破解机关的方法，她收集到了一些数据，每个数据包含一个数和两个数字标签，将以第一个数字标签从小到大排的第十个数和从第二个数字标签从大到小排的第十个数输入到机关中，机关就能破解。 
// Input
// 输入第一行为一个整数n(10<=n<=100)。其后有n行，每一行有三个正整数：题目中的“数”和两个数字标签

// Output

// 输出符合条件的两个数，以空格分开。 

// Samples

// input 
// 12
// 1234 15 36
// 1235 25 64
// 1236 51 12
// 1265 45 54
// 1554 75 45
// 1248 21 22
// 1331 45 56
// 1441 63 32
// 1551 14 13
// 1452 41 61
// 1774 74 55
// 1499 42 19
// output 
// 1441 1499


#include <stdio.h>
#include <stdlib.h>

struct info
{
    char name[10];
    int size1;
    int size2;
    struct info *next;
};

void sort(int *data, int num);
void printInfo(struct info *head, int A, int B);

int main()
{
    struct info *head = NULL;
    struct info *trail = NULL;
    struct info *pre = NULL;

    int num;
    scanf("%d", &num);
    int data1[100];
    int data2[100];
    for (int i = 0; i < num; i++)
    {
        if (i == 0)
        {
            head = (struct info *)malloc(sizeof(struct info));
            scanf("%s %d %d", head->name, &head->size1, &head->size2);
            data1[0] = head->size1;
            data2[0] = head->size2;
            head->next = NULL;
            trail = head;
        }
        else
        {
            struct info *temp = (struct info *)malloc(sizeof(struct info));
            scanf("%s %d %d", temp->name, &temp->size1, &temp->size2);
            data1[i] = temp->size1;
            data2[i] = temp->size2;
            trail->next = temp;
            temp->next = NULL;
            trail = temp;
        }
    }

    sort(data1, num);
    sort(data2, num);
    printInfo(head, data1[9], data2[num - 10]);
}

void sort(int *data, int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {

            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void printInfo(struct info *head, int A, int B)
{
    struct info *temp = head;
    while (temp != NULL)
    {
        if (temp->size1 == A)
        {
            printf("%s", temp->name);
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->size2 == B)
        {
            printf(" %s", temp->name);
        }
        temp = temp->next;
    }
}