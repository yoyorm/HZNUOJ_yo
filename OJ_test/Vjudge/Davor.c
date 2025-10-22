// Description
// After successfully conquering the South Pole, Davor is preparing for new challenges.
// Next up is the Arctic expedition to Siberia, Greenland and Norway.
// He begins his travels on 31 December 2018,
// and needs to collect N kunas (Croatian currency) by then.
// In order to do this, he has decided to put away X (x<200)kunas every Monday to his travel fund,X+Kkunas every Tuesday, X+2×K every Wednesday, and so on until Sunday, when he will put away X+6×K kunas. This way, he will collect money for 52 weeks, starting with 1 January 2018 (Monday) until 30 December 2018 (Sunday).
// If we know the amount of money N, output the values X and K so that it is possible to collect the exact money amount in the given timespan. The solution will always exist, and if there are multiple, output the one with the greatest X and smallest K.
// Input
//  The first line of input contains the integer  N ( 1456≤N≤145600), the number from the task.
//  Output
//  The first line of output must contain the value of X (0≤X≤100), and the second the value of K (K>0).
#include <stdio.h>
int main()
{
    long long targetALL;
    scanf("%lld", &targetALL);
    long long target = targetALL / 52;
    int x, k;
    for (x = 100; x >= 0; x--)
    {
        for (k = 1; k <= target / 21; k++)
        {
            if (x * 7 + k * 21 == target)
            {
                printf("%d\n%d", x, k);
                return 0;
            }
        }
    }
}