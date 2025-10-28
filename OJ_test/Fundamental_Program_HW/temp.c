#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    for(int i=0;i<num;i++)
    {
        if(i==0)
        {
            printf("   +---+\n  /     \\\n +       +\n  \\     /\n   +---+\n");
        }
        else{
            printf("  /     \\\n +       +\n  \\     /\n   +---+\n");
        }
    }
}