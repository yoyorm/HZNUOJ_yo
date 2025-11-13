#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
int main()
{
    vector<int> v;
    int temp;
    while (cin >> temp)
    {
        v.push_back(temp);
    }
    int num = v.size();
    long long sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += v[i];
    }
    sum=sum*pow(2,num-1);
    cout << sum;

}