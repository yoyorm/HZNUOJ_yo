// 判断这个日期（年-月-日）是否合法；如果合法，则返回1；如果月份不合法，则返回-1；如果月份合法且日子不合法，则返回-2，
//月份和日子都不合法，则返回-1。（年份算作永远合法）

#include<stdio.h>
#include<math.h>

int happy(int year, int month, int day);

int main() {

        char ch;

        int year, month, day;

while (scanf("%d%c%d%c%d", &year, &ch, &month, &ch, &day) != EOF) {

printf("%d ", happy(year, month, day));

}

return 0;

}


int happy(int year, int month, int day) 
{ 
    if (month > 12 || month < 1) 
        return -1;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day > 31 || day < 1)
            return -2;
        else
        {
        return 1;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day > 30 || day < 1)
            return -2;
        else
        {
            return 1;
        }
        break;
    case 2:
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            if (day > 29 || day < 1)
                return -2;
            else
            {
                return 1;
            }
        }
        else
        {
            if (day > 28 || day < 1)
                return -2;
            else
            {
                return 1;
            }
        }
        break;
    }
}