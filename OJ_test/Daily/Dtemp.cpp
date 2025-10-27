#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    int num;
    bool first = true;
    while (cin >> num)
    {
        if (!first)
            cout << endl;
        else
            first = false;
        string line;
        map<string, int> words;
        while (getline(cin, line) && line != "EndOfText")
        {
            string word = "";
            for (int i = 0; i < line.size(); i++)
            {
                if (isalpha(line[i]))
                    word += tolower(line[i]);
                else
                {
                    if (!word.empty())
                    {
                        words[word]++;
                        word = "";
                    }
                }
            }
            if (!word.empty())
            {
                words[word]++;
                word = "";
            }
        }
        bool find = false;
        for (const auto &[name, n] : words)
        {
            if (n == num)
            {
                cout << name << endl;
                find = true;
            }
        }
        if (!find)
            cout << "There are no such word." << endl;
    }
}