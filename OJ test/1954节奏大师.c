//Description
//
//�����ʦ��һ�����뿪����������������������Ϸ��july�ַǳ��ó������ʦ��
//
//��һ����osu����Ϸ�������ʦӦ�ò�࣬���Ʒ��������ģ���һ����julyһ���Ĵ��񣬲���©���κ�������ÿ�������п��������ִ��������Point��300��100��50��ʵ�ʷ�����P = Point * (Combo * 2 + 1)��Combo��ʾ��ǰ��������������������julyһ���Ĵ������ڲ���©�������������û��ĵ�i������Combo�͵���i �C 1��
//
//Input
//
//��һ������T
//
//������T�У�ÿ���������֣��ֱ����300, 100, 50���ַ����ĸ�����ÿ�����ֶ�С��1000����
//
//Output
//
//ÿ���������֣���һ���ո�ֿ����������ֱַ���AllCombo��û��©���κ��������������С��������������
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