#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int len, sizeMax;
        cin >> len >> sizeMax;

        int temp;
        vector<int> dids(len);
        for (int i = 0; i < len; i++)
        {
            cin >> temp;
            if (temp > sizeMax)
            {
                dids[i] = -1;
            }
            else
                dids[i] = temp;
        }

        vector<int> mods(len);
        for (int i = 0; i < len; i++)
        {
            cin >> temp;
            if (temp > sizeMax)
            {
                mods[i] = -1;
            }
            else
                mods[i] = temp;
        }
        sort(dids.begin(), dids.end());
        sort(mods.begin(), mods.end());

        int count = 0;

        for (int i = 0; i < len; i++)
        {
            if (dids[i] == -1)
                continue;
            for (int j = 0; j < len; j++)
            {
                if (mods[j] == -1)
                    continue;

                if (mods[j] * (dids[i]+1) < sizeMax)
                {
                    count++;
                    dids[i] = -1;
                    mods[j] = -1;
                }
            }
        }
        cout << count << endl;
    }
}