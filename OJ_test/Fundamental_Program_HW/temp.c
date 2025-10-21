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
    int *data = (int *)malloc(sizeof(int) * num);
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
            data[i] = head->size;
            trail->next = temp;
            head->next = NULL;
            trail = temp;
        }
    }

    int min = sort(data, num);
    printInfo(head, min);
}

int sort(int *data, int num)
{
    int count = 0;
    int min = 10000;
    
    for (int i = 0; i < num; i++)
    {
        if (count >= 10)
            break;
        if (min >= data[i])
        {
            min = data[i];
            count++;
        }
    }
    return min;
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