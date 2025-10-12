#include <stdio.h>
void fun0();
void fun1();
void fun2();
int main()
{
	int a;
	while (scanf("%d", &a) != EOF)
	{
		void (*ptr[3])(void) = {fun0, fun1, fun2};
		ptr[a - 1]();
	}
}

void fun0()
{
	printf("这是1号函数的打印输出。\n");
}
void fun1()
{
	printf("这是2号函数的打印输出。\n");
}
void fun2()
{
	printf("这是3号函数的打印输出。\n");
}
