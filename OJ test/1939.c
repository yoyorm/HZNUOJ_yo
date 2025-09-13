//判断一个数和2, 3的关系。
//
//Input
//
//第一行输入T，表示有T组测试数据。
//
//每组测试数据输入一个自然数n。
//
//Output
//
//如果n能被3和2整除，则输出”n divisible by 2 and 3 ? 1”，否则输出”n divisible by 2 and 3 ? 0”；
//
//如果n能被3整除或者能被2整除，则输出”n divisible by 2 or 3 ? 1”，否则输出”n divisible by 2 or 3 ? 0”；
//
//如果n能被2, 3其中一个整除则输出”n divisible by 2 or 3, but not both ? 1”，否则输出”n divisible by 2 or 3, but not both ? 0”。


//#include<stdio.h>
//void d2and3(int x);
//void d2or3(int x);
//void d2both3(int x);
//int main()
//{
//
//	int T;
//	int temp;
//	scanf_s("%d", &T);
//	for (int i = 0; i < T; i++)
//	{
//
//		scanf_s("%d", &temp);
//		d2and3(temp);
//		d2or3(temp);
//		d2both3(temp);
//
//	}
//
//	return 0;
//
//}
//void d2and3(int x)
//{
//	printf("%d divisible by 2 and 3?", x);
//	if (x % 2 == 0 && x % 3 == 0)
//	{
//		printf(" 1\n");
//	}
//	else
//	{
//		printf(" 0\n");
//	}
//}
//void d2or3(int x)
//{
//	printf("%d divisible by 2 or 3?", x);
//	if (x % 2 == 0 || x % 3 == 0)
//	{
//		printf(" 1\n");
//	}
//	else
//	{
//		printf(" 0\n");
//	}
//}
//void d2both3(int x)
//{
//	printf("%d divisible by 2 or 3, but not both?", x);
//	if (!(x % 2 == 0 && x % 3 == 0) && !(x % 2 != 0 && x % 3 != 0))
//	{
//		printf(" 1\n");
//	}
//	else
//	{
//		printf(" 0\n");
//	}
//}