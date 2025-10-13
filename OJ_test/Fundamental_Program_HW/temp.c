#include <stdio.h>
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
}