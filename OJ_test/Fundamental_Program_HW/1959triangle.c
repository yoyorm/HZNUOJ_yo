// Input
//
// ÿ�а���һ���ַ���һ������n(0 < n < 41)����ͬ���ַ���ʾ��ͬ�Ļ��ƣ�����n��ʾ���������εĸߡ���Ȼ��ױ߳�Ϊ2n - 1���������@�ַ������ʾ���������������������Ѿ����ˡ�
//
//	Output
//
//	ÿ������������֮��Ӧ����һ�У������ε��м�Ϊ�ա���Ȼ��ĩû�ж���Ŀո�
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
            if (clock > 0) // �ӵڶ������ģ�忪ʼ�м�ճ�һ��
                printf("\n\n");
            if (line == 1)
            {
                printf("%c", ch);
            }
            else
            {
                for (int i = 0; i < blank1; i++)
                    printf(" ");
                printf("%c\n", ch); // �ȴ��һ��
                if (line >= 3)
                {
                    blank1--;
                    for (int i = 0; i < line - 2; i++) // �м���
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

                for (int p = 0; p < max; p++) // �������һ��
                    printf("%c", ch);
            }
            clock++;
        }
    }
    return 0;
}