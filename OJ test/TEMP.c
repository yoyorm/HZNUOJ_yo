#include<stdio.h>
int main()
{
	int T;
	int data[100];
	scanf_s("%d", &T);
	{
		for(int i=0;i<T;i++)
		{
			int temp,max=0;
			scanf_s("%d", &temp);
			for (int a = 0; a * 150 <= temp; a++)
			{
				for (int b = 0; a * 150 + b * 200 <= temp; b++)
				{
					for (int c = 0; a * 150 + b * 200 + c * 350 <= temp; c++)
					{
						if (a * 150 + b * 200 + c * 350 > max)
							max = a * 150 + b * 200 + c * 350;
					}
				}
			}
			data[i] = temp - max;
		}
		for (int k = 0; k < T; k++)
		{
			printf("%d\n", data[k]);
		}

	}
	return 0;
}

