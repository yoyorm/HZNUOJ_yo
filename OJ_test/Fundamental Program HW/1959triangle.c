// Input
//
// 每行包含一个字符和一个整数n(0 < n < 41)，不同的字符表示不同的花纹，整数n表示等腰三角形的高。显然其底边长为2n - 1。如果遇到@字符，则表示所做出来的样板三角形已经够了。
//
//	Output
//
//	每个样板三角形之间应空上一行，三角形的中间为空。显然行末没有多余的空格。
//
//	Samples
//
//	input
//	X 2
//	A 7
//	@
//	output
//	 X
//	XXX

#include <stdio.h>
int main()
{
    int clock = 0;
    char ch;
    int line, max;
    while (scanf(" %c", &ch, 1) == 1 && ch != '@')
    {
        scanf("%d", &line);

        if (line >= 1)
        {
            max = line * 2 - 1;
            int blank1 = line - 1;
            int blank2 = 1;
            if (clock > 0) // 从第二个输出模板开始中间空出一行
                printf("\n\n");
            if (line == 1)
            {
                printf("%c", ch);
            }
            else
            {
                for (int i = 0; i < blank1; i++)
                    printf(" ");
                printf("%c\n", ch); // 先打第一行
                if (line >= 3)
                {
                    blank1--;
                    for (int i = 0; i < line - 2; i++) // 中间行
                    {
                        for (int k = 0; k < blank1; k++)
                            printf(" ");
                        printf("%c", ch);
                        for (int j = 0; j < blank2; j++)
                            printf(" ");
                        printf("%c\n", ch);
                        blank1--;
                        blank2 += 2;
                    }
                }

                for (int p = 0; p < max; p++) // 填满最后一行
                    printf("%c", ch);
            }
            clock++;
        }
    }
    return 0;
}