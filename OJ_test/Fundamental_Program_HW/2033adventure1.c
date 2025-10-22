// 【C系列7.8】结构-8：女神历险记1 AC 2033

// Description
// 最近loy看了盗墓笔记，对古墓中的各种机关结构产生了极大的好奇心。这不，她不知道在哪百度了一串古墓群的某种参数，并坚信这些参数之间有着某种联系。被她研究了不知道有多久，还真被找出了某些关联：每个参数经过一种奇特的运算都能得到一种优先级，当删除了部分优先级低的参数，巨大的秘密就会展现在我们的面前。。。。。。当然，她忙着激动了，就把算出来的数据扔给你，让你来帮她揭开这个巨大的秘密。 

// Input

// 第一行为一个正整数n(10<n<=100)，其后有n行，每一行有两个数，前面是古墓的参数(可能会带前导0)，后面是古墓的优先级(保证了优先级不会重复出现)。
// Output

// 去掉优先级最低的前10个参数，将剩下的参数按原出现顺序输出，以空格分隔(行末不得出现多余空格)。 

// Samples

// input 
// 12
// 0000 20
// 0001 19
// 0010 18
// 0011 17
// 0100 16
// 0101 15
// 0110 14
// 0111 13
// 1000 12
// 1001 11
// 1010 10
// 1011 9 

// output 
// 0000 0001



#include <stdio.h>
#include <stdlib.h>

struct info
{
    char name[10];
    int size;
    struct info *next;
};

int sort(int *data, int num);
void printInfo(struct info *head, int min);

int main()
{
    struct info *head = NULL;
    struct info *trail = NULL;
    struct info *pre = NULL;

    int num;
    scanf("%d", &num);
    int data[100];
    for (int i = 0; i < num; i++)
    {
        if (i == 0)
        {
            head = (struct info *)malloc(sizeof(struct info));
            scanf("%s %d", head->name, &head->size);
            data[0] = head->size;
            head->next = NULL;
            trail = head;
        }
        else
        {
            struct info *temp = (struct info *)malloc(sizeof(struct info));
            scanf("%s %d", temp->name, &temp->size);
            data[i] = temp->size;
            trail->next = temp;
            temp->next = NULL;
            trail = temp;
        }
    }

    int min = sort(data, num);
    printInfo(head, min);
}

int sort(int *data, int num)
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
    return data[9];
}

void printInfo(struct info *head, int min)
{
    int count = 0;
    struct info *temp = head;
    while (temp != NULL)
    {
        if (temp->size > min)
        {
            if (count == 0)
            {
                printf("%s", temp->name);
                count++;
            }
            else
            {
                printf(" %s", temp->name);
                count++;
            }
        }
        temp = temp->next;
    }
}