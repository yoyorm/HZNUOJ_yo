#include <stdio.h>
#include <string.h>

int find(char *s);
void throwAB(char *s, int pos);
int count = 0;
int main()
{
    char s[500];
    while (fgets(s, 500, stdin) != NULL)
    {
        throwAB(s, 0);
        int result = find(s);
        if (result)
        {
            printf("yu ye sa wang dai xing\n");
        }
        else
        {
            printf("zhen shi ou ba\n");
        }
    }
    return 0;
}

void throwAB(char *s, int pos)
{
    if (pos > strlen(s) - 3)
        if (count > 0 && s[pos] != s[pos + 1])
        {
            s[pos] = '0';
            s[pos + 1] = '0';
            return;
        }

    if (s[pos] != s[pos + 1] && s[pos + 1] != s[pos + 2])
    {
        s[pos] = '0';
        count++;
    }
    else
    {
        if (count > 0)
        {
            s[pos] = '0';
            s[pos + 1] = '0';
        }
        count = 0;
    }
    throwAB(s, pos + 1);
}

int find(char *s)
{
    int AB = 0, BA = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'A')
        {
            if (s[i + 1] == 'B')
            {
                AB++;
            }
            i++;
        }
        else if (s[i] == 'B')
        {
            if (s[i + 1] == 'A')
            {
                BA++;
            }
            i++;
        }
    }
    if (AB && BA)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}