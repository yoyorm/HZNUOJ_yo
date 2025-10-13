#include <stdio.h>
<<<<<<< HEAD
#include <string.h>
void showName(char x[]);
int main()
{
	int c;
	char file[10];
	file[9] = '\0';
	while ((c = getchar()) != '.'&& c != EOF )
	{
	}
	scanf("%s", &file);
	showName(file);
}

void showName(char x[])
{
	if (strcmp(x, "doc") == 0)
		printf("Word\n");
	if (strcmp(x, "xls") == 0)
		printf("Excel\n");
	if (strcmp(x, "ppt") == 0)
		printf("PowerPoint\n");
=======
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
>>>>>>> 27f5a2047527a3ee21df3d2e99ebd48d6a676167
}