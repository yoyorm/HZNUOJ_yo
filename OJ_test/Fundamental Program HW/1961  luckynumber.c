// Description

// 幸运数第二波来袭了。聪明的hhhh给zjf出了个奇怪的问题。hhhh给zjf一个数，判定这个数是不是完全幸运。完全幸运的条件是对于一个数中所有的数字来说，首先只能由4或7组成，其次，设4和7在数字中出现的次数为x，那么x也只能由4或7组成。聪明如你，来帮一先zjf吧。

// Input

// 一个数n(0<n<10^9）。

// Output

// 如果是的则输出YES，否则输出NO。

#include <stdio.h>
void lucky_number(long long n, int *data);

int main()
{
    long long T;
    int data[3] = {0, 0, 0};
    scanf("%lld", &T);
    lucky_number(T, data);
    if (data[0] == 0)
    {
        printf("NO");
        return 0;
    }
    else
    {
        long long x = data[1] + data[2];
        int data2[3] = {0, 0, 0};
        lucky_number(x, data2);
        if (data2[0] == 1)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
    }
}

void lucky_number(long long n, int *data)
{
    while (n > 0)
    {
        if (n % 10 != 4 && n % 10 != 7)
        {
            data[0] = 0;
            return;
        }
        else
        {
            if (n % 10 == 4)
            {
                data[1]++;
            }
            else
            {
                data[2]++;
            }
        }
        n /= 10;
    }
    data[0] = 1;
}