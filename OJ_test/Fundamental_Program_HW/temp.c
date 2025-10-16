#include <stdio.h>
#include <string.h>
void print(char *num, int length);

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        char num[22];
        fgets(num, 22, stdin);
        int len = strlen(num);
        print(num, len);
        printf("\n");
    }

    return 0;
}

void print(char *num, int length)
{
    for (int i = 0; i < length; i++)
    {
        switch (num[i])
        {
        case '0':
            printf("zero ");
            break;
        case '1':
            printf("one ");
            break;
        case '2':
            printf("two ");
            break;
        case '3':
            printf("three ");
            break;
        case '4':
            printf("four ");
            break;
        case '5':
            printf("five ");
            break;
        case '6':
            printf("six ");
            break;
        case '7':
            printf("seven ");
            break;
        case '8':
            printf("eight ");
            break;
        case '9':
            printf("nine ");
            break;
        }
    }
}