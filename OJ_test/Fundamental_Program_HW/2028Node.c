// 【C系列7.3】结构-3
// Description
// loy最近被分配给了一个任务：将队里的队员信息表补充完整，然而她实在是太懒了，就把这项任务推给了你，你能帮助她吗？
// Input
// 多组输入
// 第一行给出两个正整数n,t(0<n,t<=3000)，其后有一行，包含n个正整数id（以空格分隔,0<id<1e9），为该学生的学号。
// 接下来有t行，每行有两个正整数x,y，x为新队员的id，y为现有队员的id，将x插入到y的前面。
// Output
// 输出最终的队员信息表。

// Samples
// input
// 5 4
// 1001 1002 1003 1004 1005
// 1006 1004
// 1007 1004
// 1008 1006
// 1009 1001
// output
// 1009 1001 1002 1003 1008 1006 1007 1004 1005
// Hint
// 1. 队员的学号可能重复；2. 当学号重复的时候，插入到靠前的学号之前。

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    long long id;
    struct Node *next;
};

void printNode(struct Node *head);
void inputNode(struct Node **head, int num);
void insertNode(struct Node **head);

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        struct Node *head = NULL;
        inputNode(&head, n);
        while (m--)
        {
            insertNode(&head);
        }
        printNode(head);
    }
}

void inputNode(struct Node **head, int num)
{
    struct Node *tail = NULL;
    for (int i = 0; i < num; i++)
    {

        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%lld", &temp->id);
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
}

void insertNode(struct Node **head)
{
    long long idto, findid;
    scanf("%lld %lld", &idto, &findid);
    struct Node *pre = NULL;
    struct Node *cur = *head;
    while (cur != NULL)
    {
        if ((cur)->id == findid)
        {
            if (pre == NULL)
            {
                struct Node *temp = cur;
                struct Node *newhead = (struct Node *)malloc(sizeof(struct Node));
                newhead->id = idto;
                newhead->next = temp;
                *head = newhead;
            }
            else
            {
                struct Node *newhead = (struct Node *)malloc(sizeof(struct Node));
                newhead->id = idto;
                newhead->next = (cur);
                pre->next = newhead;
            }
            return;
        }
        pre = cur;
        cur = (cur)->next;
    }
}
void printNode(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%lld ", temp->id);
        temp = temp->next;
    }
    printf("\n");
}