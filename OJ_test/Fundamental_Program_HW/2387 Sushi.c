//Description
//
//��һ�Σ���������������ʱ������һλ���ڵ�������ţ��������������ŵĵ�����ϲ�û�й��ӣ������е��ǳ���֣��������������ŵ�ʱ�����Ŷ�������һ��ͼֽ��˵�������Ŵ˺�����һ�����أ����ռ�����Ե���Ͱ���ر�ͼ������ա���˵���ﳤ��ȥ��
//
//�����򿪲ر�ͼ������д�š�������ǳ�����ϱ����������˼������ر���ĵ������ڵ�ͬһˮƽ����ˮ������ǳ�ģ�ͬʱ�����ڵ�ͬһ��ֱ����������ģ�������������ˮ�����ͼ��
//
//��ɷ���������ҵ��˱����أ�
//
//Input
//
//ֻ��һ������
//
//��һ������n��m(1 <= n, m <= 100)���ֱ��ʾ�������ϱ����򳤶ȺͶ������򳤶�
//
//������n��ÿ������m�����ݣ���ʾ������ĺ�ˮˮ��
//
//��֤ÿ����������ֻ��һ�������ĵ㣬��ÿ��ˮ�ͬ
//
//Output
//�����������
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