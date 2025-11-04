#include <iostream>
using namespace std;
void sort(int *arr, int num);
int main()
{
    short T;
    cin >> T;
    while (T--)
    {
        int num, pos;
        cin >> num >> pos;
        int *arr = new int[num];
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        sort(arr, num);
        cout << arr[pos] << endl;
    }
}

void sort(int *arr, int num)
{
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (arr[j] / 10 % 10 > arr[j + 1] / 10 % 10)
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            if (arr[j] / 10 % 10 == arr[j + 1] / 10 % 10)
            {
                if (arr[j] / 100 % 10 > arr[j + 1] / 100 % 10)
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
                if (arr[j] / 100 % 10 == arr[j + 1] / 100 % 10)
                {
                    if (arr[j] % 10 > arr[j + 1] % 10)
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
    }
}
