//�ж�һ������2, 3�Ĺ�ϵ��
//
//Input
//
//��һ������T����ʾ��T��������ݡ�
//
//ÿ�������������һ����Ȼ��n��
//
//Output
//
//���n�ܱ�3��2�������������n divisible by 2 and 3 ? 1�������������n divisible by 2 and 3 ? 0����
//
//���n�ܱ�3���������ܱ�2�������������n divisible by 2 or 3 ? 1�������������n divisible by 2 or 3 ? 0����
//
//���n�ܱ�2, 3����һ�������������n divisible by 2 or 3, but not both ? 1�������������n divisible by 2 or 3, but not both ? 0����


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