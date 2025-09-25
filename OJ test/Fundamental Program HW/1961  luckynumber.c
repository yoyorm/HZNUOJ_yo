#include <stdio.h>
int main()
{
    long long int n;
    int four = 0, seven = 0;
    scanf("%lld", &n);
    while (n > 0)
    {
        if (n % 10 != 4 && n % 10 != 7)
        {
            printf("NO");
            return 0;
        }
        else
        {
            if (n % 10 == 4)
            {
                four++;
            }
            else
            {
                seven++;
            }
        }
        n /= 10;
    }
    if (four != 4 && four != 7 || seven != 4 && seven != 7)
    {
        printf("NO");
        return 0;
    }
    else
    {
        printf("YES");
    }
}