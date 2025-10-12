#include <stdio.h>
void change(int *a[3][3]);
int main()
{
	int *data[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &data[i][j]);
		}
	}
	change(data);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void change(int *a[3][3])
{
	int* b[3][3]= a;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}
