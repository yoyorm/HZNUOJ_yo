#include <iostream>
using namespace std;
int main()
{
    int T;

    while (cin >> T)
    {
        int *data = new int[T];
        for (int i = 0; i < T; i++)
        {
            cin >> data[i];
        }
        for (int i = T - 1; i >= 0; i--)
        {
            if (i != 0)
            {
                cout << data[i] << " ";
            }
            else
            {
                cout << data[i] << endl;
            }
        }
        free(data);
    }

    return 0;
}