#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int all, num;
    cin >> all >> num;
    int *a = new int[all];
    for (int i = 0; i < all; i++)
    {
        cin >> a[i];
    }
    sort(a, a + all,greater<int>());
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += a[i];
    }
    double ans = sum / 1000.0;
    printf("%.2f", ans);
}
