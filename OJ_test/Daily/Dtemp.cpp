#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int x;

    while (scanf("%d", &x) != EOF)
    {
        vector<int> v(0);
        for (int i = 1; i <= x; i++)
        {
            v.push_back(i);
        }
        sort(v.begin(), v.end());
        do
        {
            for (int i = 0; i < v.size(); i++)
            {
                printf("%d", v[i]);
            }
            printf("\n");
        } while (next_permutation(v.begin(), v.end()));
        sort(v.begin(), v.end(), greater<int>());
        do
        {
            for (int i = 0; i < v.size(); i++)
            {
                printf("%d", v[i]);
            }
            printf("\n");
        } while (prev_permutation(v.begin(), v.end()));
        printf("\n");
    }
}