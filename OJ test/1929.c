//Input
//
//矩阵的宽n（0 < n < 10）和长m（0 < m < 10）。
//
//	Output
//
//	以 * 号表示，请打印出矩形。
//
//	Samples
//
//	input
//	1 3
//	output
//	***

//#include<stdio.h>
//int main()
//{
//	int line,column;
//	scanf_s("%d%d", &line, &column);
//	int x = 1;
//	while (x <= line)
//	{
//		int y = 1;
//		if (x == 1 ||x==line)
//		{
//			for (y; y <= column; y++)
//			{
//				printf("*");
//			}
//			printf("\n");
//		}
//		else
//		{
//			for (y; y <= column; y++)
//			{
//				if(y==1||y==column)
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//			}
//			printf("\n");
//		}
//		x++;
//	}
//	return 0;
//}