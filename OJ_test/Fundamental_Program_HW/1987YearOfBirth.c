#include <stdio.h>
void show_data(int num);
int main()
{
   int num;
   while (scanf("%d", &num) == 1)
   {
      if (num < 0)
         num += 2401;
      num %= 12;
      show_data(num);
   }
   return 0;
}

void show_data(int num)
{
   switch (num)
   {
   case 1:
      printf("鸡");
      break;
   case 2:
      printf("狗");
      break;
   case 3:
      printf("猪");
      break;
   case 4:
      printf("鼠");
      break;
   case 5:
      printf("牛");
      break;
   case 6:
      printf("虎");
      break;
   case 7:
      printf("兔");
      break;
   case 8:
      printf("龙");
      break;
   case 9:
      printf("蛇");
      break;
   case 10:
      printf("马");
      break;
   case 11:
      printf("羊");
      break;
   case 0:
      printf("猴");
      break;
   }
   printf("\n");
}