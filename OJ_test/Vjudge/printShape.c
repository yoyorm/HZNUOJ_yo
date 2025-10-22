// Description
// 模仿例题，打印出不同方向的正方形，然后打印三角形矩阵。中间有个空行。

// Input
// 输入矩阵的规模，不超过
// 9

// Output
// 输出矩形和正方形
// Sample 1
// Inputcopy
// 4
// 01020304
// 05060708
// 09101112
// 13141516
// Outputcopy
//       01
//     0203
//   040506
// 07080910

#include <stdio.h>
#include <stdlib.h>
void setValue(char **arr, short num);
void printSquare(char **arr, short num);
void printTriangle(char **arr, short num);
int main()
{
    short num;
    scanf("%hd", &num);
    char **arr = (char **)malloc(num * num * sizeof(char *));
    for (int i = 0; i < num * num; i++)
    {
        arr[i] = (char *)malloc(3 * sizeof(char));
        arr[i][2] = '\0';
    }
    setValue(arr, num);
    printSquare(arr, num);
    printf("\n");
    printTriangle(arr, num);
}

void setValue(char **arr, short num)
{
    for (int i = 0; i < num * num; i++)
    {
        if (i < 9)
        {
            arr[i][0] = '0';
            arr[i][1] = (i + 1) + '0';
        }
        else
        {
            arr[i][0] = (i + 1) / 10 + '0';
            arr[i][1] = (i + 1) % 10 + '0';
        }
    }
}
void printSquare(char **arr, short num)
{
    int count = 0;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            printf("%s", arr[count++]);
        }
        printf("\n");
    }
}

void printTriangle(char **arr, short num)
{
    int count = 0;
    int blank = num - 1;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (j <= blank)
            {
                printf("  ");
            }
            else
            {
                printf("%s", arr[count++]);
            }
        }
        printf("\n");
        blank--;
    }
}