//Description
//
//在数字界有一类被叫做幸运数的数，其实幸运数的组成很简单。如果一个数所有位数上的数字都是4或7的话就叫做幸运数。比如444444, 44747是幸运数而57774747就不是。
//
//现在mwy遇到了一个小问题，他只知道一个幸运数所有位数上数字之和，他想知道这个数最小会是多少，聪明如你，快来帮帮我们的mwy吧。
//
//Input
//
//输入一个数n（n <= 300）。
//
//Output
//
//如果可以找到这样的幸运数，就输出这个幸运数，否则就输出 - 1。
//
//Samples
//
//input
//12
//output
//444

//#include<stdio.h>
//int main()
//{
//	int size;
//	scanf_s("%d", &size);
//	int fsize, ssize;
//	int x4=0, y7=0;
//	int all;
//	int find = 0;
//	for (int i = 0; i < 76; i++)
//	{
//		fsize = 4 * i;
//		for (int j = 0; j < 43; j++)
//		{
//			if (find > 0)
//				break;
//			ssize = 7 * j;
//			all = fsize + ssize;
//			if (all == size)
//			{
//				x4 = i;
//				y7 = j;
//				find++;
//			}
//			if (i == 75 && j == 42 && find==0)
//				printf("-1");
//		}
//	}
//	if(find!=0)
//	{
//		for (int k = 0; k < x4; k++)
//		{
//			printf("4");
//		}
//		for (int k = 0; k < y7; k++)
//		{
//			printf("7");
//		}
//	}
//	return 0;
//}