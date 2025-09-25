//Description
//
//节奏大师是一个能与开心消消乐相媲美的娱乐游戏，july兄非常擅长节奏大师。
//
//有一个叫osu的游戏跟节奏大师应该差不多，它计分是这样的：有一个像july一样的大神，不会漏掉任何音符，每个音符有可能有三种待处理分数Point，300，100，50。实际分数是P = Point * (Combo * 2 + 1)。Combo表示当前的连续音符数，对于像july一样的大神，由于不会漏音符，所以他敲击的第i个音符Combo就等于i – 1。
//
//Input
//
//第一行输入T
//
//接下来T行，每行三个数字，分别代表300, 100, 50三种分数的个数（每个数字都小于1000）。
//
//Output
//
//每行两个数字，用一个空格分开，两个数字分别是AllCombo（没有漏掉任何音符）情况下最小分数和最大分数。
//
//Samples
//
//input
//1
//2 1 1
//output
//2050 3950



//#include<stdio.h>
//int calculateMAX(int max, int midd, int min);
//int main()
//{
//	int max, min, midd, total;
//	int T;
//	while (scanf_s("%d", &T) == 1)
//	{
//		for (int i = 0; i < T; i++)
//		{
//			scanf_s("%d%d%d", &max, &midd, &min);
//			printf("%d %d\n", calculateMIN(max, midd, min), calculateMAX(max, midd, min));
//
//		}
//	}
//	return 0;
//}
//
//int calculateMAX(int max, int midd, int min)
//{
//	int total = max + midd + min;
//	int result = 0;
//	for (int combo = 0; combo < total; combo++)
//	{
//		if (min > 0)
//		{
//			result += 50 * (combo * 2 + 1);
//			min--;
//		}
//		else if (midd > 0)
//		{
//			result += 100 * (combo * 2 + 1);
//			midd--;
//		}
//		else if (max > 0)
//		{
//			result += 300 * (combo * 2 + 1);
//			max--;
//		}
//	}
//	return result;
//}
//
//int calculateMIN(int max, int midd, int min)
//{
//	int total = max + midd + min;
//	int result = 0;
//	for (int combo = 0; combo < total; combo++)
//	{
//		if (max > 0)
//		{
//			result += 300 * (combo * 2 + 1);
//			max--;
//		}
//
//		else if (midd > 0)
//		{
//			result += 100 * (combo * 2 + 1);
//			midd--;
//		}
//		else if (min > 0)
//		{
//			result += 50 * (combo * 2 + 1);
//			min--;
//		}
//
//	}
//	return result;
//}