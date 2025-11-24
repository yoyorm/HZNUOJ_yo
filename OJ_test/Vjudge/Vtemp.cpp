#include <iostream>
#include <vector>
using namespace std;

void insertSort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int temp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > temp)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j+1] = temp;
    }
}

int main()
{
    vector<int> v = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42, 35, 17, 8, 99, 23, 67, 45, 78, 33};
    insertSort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

