//Description
//
//��Ҫ����Ӽ�������һ������n��1 <= n <= 9������ӡ��ָ��������ͼ�Ρ�
//
//Input
//
//�����������������ݡ�ÿ������һ������n��1 <= n <= 9����
//
//Output
//
//����ÿ�����룬���ָ��������ͼ�Ρ�
//
//ע�⣺ÿ�����һ�����ֺ�û���κοո�
//
//Samples
//
//input
//5
//output
//     1
//    121
//   12321
//  1234321
// 123454321
//  1234321
//   12321
//    121
//     1


#include<stdio.h>
int main()
{
	
	int x;
	while(scanf_s("%d", &x)==1)
	{
		int lineMAX = (x - 1) * 2 + 1;
		int blank = x;
		int line = 1;
		int temp = 1;
		while (line <= x)//�����ϰ���м��
		{
			int reachMAX = 0;
			temp = 1;
			for (int blanktemp = 0; blanktemp < blank; blanktemp++)
				printf(" ");
			blank--;
			while (temp <= line)
			{
				printf("%d", temp);
				temp++;
				if (temp == line)
					reachMAX = 1;
			}
			if (reachMAX == 1)
			{
				temp -= 2;
				while (temp > 0)
				{
					printf("%d", temp);
					temp--;
				}
			}
			printf("\n");
			line++;
		}
		blank += 2; //������ȥ�Ŀո�
		int midd = x - 1;//���µı��������²����������
		while (line > x && line <= lineMAX)//�����¶�
		{
			int reachMAX = 0;
			temp = 1;
			for (int blanktemp = 0; blanktemp < blank; blanktemp++)
				printf(" ");
			blank++;
			while (temp <= midd)
			{
				printf("%d", temp);
				temp++;
				if (temp == midd)
					reachMAX = 1;
			}
			if (reachMAX == 1)
			{
				temp -= 2;
				while (temp > 0)
				{
					printf("%d", temp);
					temp--;
				}
			}
			
			printf("\n");
			
			midd--;
			line++;
		}
	}
}