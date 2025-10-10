//Description
//
//先要求你从键盘输入一个整数n（1 <= n <= 9），打印出指定的数字图形。
//
//Input
//
//输入包含多组测试数据。每组输入一个整数n（1 <= n <= 9）。
//
//Output
//
//对于每组输入，输出指定的数字图形。
//
//注意：每行最后一个数字后没有任何空格。
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
		while (line <= x)//处理上半和中间段
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
		blank += 2; //补充多减去的空格
		int midd = x - 1;//用新的变量控制下部分最大数字
		while (line > x && line <= lineMAX)//处理下端
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