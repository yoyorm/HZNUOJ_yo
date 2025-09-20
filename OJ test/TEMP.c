#include<stdio.h>
int main()
{
	
	int num = 1;
	int add=0;
	while (num <= 100)
	{
		if (num % 2 == 0)
			add += num;
		num++;
	}
	printf("%d", add);
	return 0;
}


