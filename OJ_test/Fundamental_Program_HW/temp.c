#include <stdio.h>
int main()
{
	int T;

	while (scanf("%d", &T) != EOF)
	{
		int data[100];
		for (int i = 0; i < T; i++)
		{
			scanf("%d", &data[i]);
		}
		for (int i = T - 1; i >= 0; i--)
		{
			if (i != 0)
			{
				printf("%d ", data[i]);
			}
			else
			{
				printf("%d\n", data[i]);
			}
		}
	}
	return 0;
}