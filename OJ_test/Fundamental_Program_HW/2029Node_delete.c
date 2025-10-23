// 【C系列7.4】结构-4 善于总结 AC 2029
// Description
// 最近acm队决定对近期举行的n场比赛做一总结，以研究哪几场比赛题目难度分配正常，但苦于任务艰巨没人想做，所以就找上你啦~~~
// Input
//  第一行为一个正整数n（0<n<100），接下来有n行。对于每一行有9个整数，第一个整数为比赛序号，接下来八个代表第1~8题的成功解题人数。
// Output
// 输出难度分配最简单的比赛的序号。若题号越小的题目解出的人数越多，则该比赛越简单。（当然和现实的acm赛有区别）
// Samples
// input
// 5
// 1 200 300 400 500 600 700 800 900
// 2 900 900 800 700 600 400 200 100
// 3 900 800 700 600 500 400 300 200
// 4 800 800 800 800 800 800 800 800
// 5 1 2 3 4 5 6 7 8
// output
// 2
// Hint
// 1. 以样例为例
// 先看第一题，做出来最多的是2、3号比赛
// 继续看第二题，2号做出来的比3号多
// 所以答案是2号
// 2. 序号不一定是连续的，可以是任何int类型的整数。

#include <stdio.h>
#include <stdlib.h>

struct Node
//创建双向链表（虽然这题用不到双向指针）
{
    struct Node *prev;
    int id;
    int data[8];
    struct Node *next;
};
int count(struct Node *head);
void deleteHead(struct Node **head);
void findEasy(struct Node **head);
// void printList(struct Node *head);

int main()
{
    int N;
    scanf("%d", &N);
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    //创建链表头！
    struct Node *trail = (struct Node *)malloc(sizeof(struct Node));
    //创建一个链表暂时用于处理链表尾部创建
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        //头部要分开讨论
        {
            scanf("%d", &head->id);
            for (int j = 0; j < 8; j++)
            {
                scanf("%d", &head->data[j]);
            }
            head->next = NULL;
            head->prev = NULL;
            trail = head;
        }
        else
        {
            struct Node *p = (struct Node *)malloc(sizeof(struct Node));
            scanf("%d", &p->id);
            for (int j = 0; j < 8; j++)
            {
                scanf("%d", &p->data[j]);
            }
            p->next = NULL;
            p->prev = trail;
            trail->next = p;
            trail = p;
        }
    }
    // printList(head);
    findEasy(&head);
}

int count(struct Node *head)
//计算链表长度
{
    int count = 0;
    while (head != NULL)
    {

        head = head->next;
        count++;
    }
    return count;
}

void deleteHead(struct Node **head)
// 删除链表头
{
    struct Node *temp = (*head);
    *head = (*head)->next;
    if ((*head) != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

void findEasy(struct Node **head)
{
    int pos = 0;
    while (count(*head) != 1 && pos < 8)
    {
        struct Node *current = *head;
        struct Node *MAX = *head;
        int max = (*head)->data[pos];
        current = current->next;
        while (current != NULL)
        //遍历链表寻找最大值先
        {
            if (current->data[pos] > max)
            {
                max = current->data[pos];
                MAX = current;
            }
            current = current->next;
        }
        current = *head;//充值遍历头位置

        while (current != NULL)
        // 再遍历链表寻找小于最大值的节点，然后删除
        {
            struct Node *Next = current->next;
            //由于涉及到删除现在位置的链表，要提前备好下一个链表的位置，到时候复制给当前链表
            if (current->data[pos] < max)
            {
                if (current == *head)
                {
                    deleteHead(head);
                }
                else
                {
                    current->prev->next = current->next;
                    if (current->next != NULL)
                    {
                        current->next->prev = current->prev;
                    }
                    free(current);
                }
            }
            current = Next;//链表移动到下一个位置
        }
        // printList(*head);
        pos++;//对比的数组位置向后移动一个
    }
    printf("%d", (*head)->id);
}

// void printList(struct Node *head)
// {
//     printf("List: ");
//     while (head != NULL)
//     {
//         printf("%d ", head->id);
//         for (int i = 0; i < 8; i++)
//             printf("%d ", head->data[i]);
//         printf("\n");
//         head = head->next;
//     }
//     printf("\n");
// }