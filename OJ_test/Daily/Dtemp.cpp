#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int num;
        cin >> num;
        map<string, int> stu;
        while (num--)
        {
            string name;
            int score;
            cin >> name >> score;
            stu[name] = score;
        }
        cin >> num;
        while (num--)
        {
            string name;
            cin >> name;
            if (stu.count(name))
                cout << stu[name] << endl;
            else
                cout << "error" << endl;
        }
    }
}