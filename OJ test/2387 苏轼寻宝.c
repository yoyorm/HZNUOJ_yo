//Description
//
//有一次，苏轼在西湖钓鱼时遇到了一位正在钓鱼的老叟，可是他发现老叟的钓鱼竿上并没有钩子，苏轼感到非常奇怪，正当他想问老叟的时候，老叟丢给了他一张图纸，说：“传闻此湖中有一个宝藏，今日见你有缘，就把这藏宝图赠与你罢”，说完扬长而去。
//
//苏轼打开藏宝图，上面写着“东西最浅，且南北最深处”，意思就是埋藏宝物的点在所在的同一水平线上水深是最浅的，同时在所在的同一竖直线上是最深的，后面是西湖的水深地形图。
//
//你可否帮助苏轼找到此宝藏呢？
//
//Input
//
//只有一组输入
//
//第一行输入n，m(1 <= n, m <= 100)，分别表示西湖的南北方向长度和东西方向长度
//
//接下来n行每行输入m个数据，表示各坐标的湖水水深
//
//保证每组数据有且只有一个这样的点，且每处水深不同
//
//Output
//输出宝藏坐标
//Samples
//
//input
//3 3
//1 2 3
//4 5 6
//7 8 9
//output
//(3, 1)

//#include<stdio.h>
//int low(int array[][100], int y, int x, int max);
//int high(int array[][100], int y, int x, int max);
//int main() 
//{
//	int xray, yray;
//	scanf_s("%d%d", &yray, &xray);
//	int line[100][100];
//	for(int j=0;j<yray;j++)
//	{
//		for (int i=0; i < xray; i++)
//		{
//			scanf_s("%d", &line[j][i]);
//		}
//	}
//	int pos[2] = {0,0};
//	for (int j = 0; j < yray; j++)
//	{
//		for (int i = 0; i < xray; i++)
//		{
//			if (low(line, j, i, xray) && high(line, j, i, yray))
//			{
//				pos[0] = j;
//				pos[1] = i;
//			}
//		}
//	}
//	
//	printf("(%d,%d)", pos[0]+1, pos[1]+1);
//	return 0;
//}
//
//int low(int array[][100],int y,int x,int max)
//{
//	for (int i = 0; i < max; i++)
//	{
//		if (array[y][x] > array[y][i])
//			return 0;
//	}
//	return 1;
//}
//int high(int array[][100], int y, int x, int max)
//{
//	for (int i = 0; i < max; i++)
//	{
//		if (array[y][x] < array[i][x])
//			return 0;
//	}
//	return 1;
//}