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
// 链表结构
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
        // 创建列表
        inputNode(&head, n);
        // 使用&来传递**Node类型，只有这样才可以修改链表头节点，否则智能修改内容
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
            // 如果是链表头，就直接初始化为头尾
        }
        else
        {
            tail->next = temp;
            // 将上一个尾部的next指针指向新节点
            tail = temp;
            // 把新节点赋给尾部
        }
    }
}

void insertNode(struct Node **head)
{
    long long idto, findid;
    scanf("%lld %lld", &idto, &findid);
    struct Node *pre = NULL;
    // 用于修改前一个链表的next和判断链表头
    struct Node *cur = *head;
    // 创建临时指针用于遍历链表（防止修改原链表）
    while (cur != NULL)
    {
        if ((cur)->id == findid)
        {
            if (pre == NULL)
            {
                // 如果插入位置是链表头，就创建一个新的链表，并且赋值之后赋给链表头
                struct Node *newhead = (struct Node *)malloc(sizeof(struct Node));
                newhead->id = idto;
                newhead->next = cur;
                *head = newhead;
            }
            else
            {
                // 中间位置就创建一个新的链表，修改前一个链表与当前的next连接前后节点
                struct Node *newhead = (struct Node *)malloc(sizeof(struct Node));
                newhead->id = idto;
                newhead->next = (cur);
                pre->next = newhead;
            }
            return;
            // 找到插入之后就立刻结束
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
        // 通过临时指针遍历链表
    }
    printf("\n");
}