#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int T;
	while (scanf("%d", &T) == 1)
	{
		int *data = (int *)malloc(sizeof(int) * T);
		for (int i = 0; i < T; i++)
		{
			scanf("%d", &data[i]);
		}
		int change = 1;
		for (int i = 0; i < T; i++)
		{
			if (change == 0)
			{
				break;
			}
			change = 0;
			for (int *p = data; p < data + T - 1; p++) // 多减一防止访问越界
			{
				if (abs(*p) > abs(*(p + 1)))
				{
					int temp = *p;
					*p = *(p + 1);
					*(p + 1) = temp;
					change++;
				}
			}
		}
		for (int i = 0; i < T; i++)
		{
			if (i < T - 1)
			{
				printf("%d ", data[i]);
			}
			else
			{
				printf("%d\n", data[i]);
			}
		}
		printf("\n");
	}
}