
// Description
// Problem D - Zipf's Law
// Harvard linguistics professor George Kingsley Zipf (1902-1950) observed that the frequency of the kth most common word in a text is roughly proportional to 1/k. He justified his observations in a book titled Human behavior and the principle of least effort published in 1949. While Zipf's rationale has largely been discredited, the principle still holds, and others have afforded it a more sound mathematical basis.

// Input

// Input consists of several test cases. The first line of each case contains a single positive integer n. Several lines of text follow which will contain no more than 10000 words. The text for each case is terminated by a single line containing EndOfText. EndOfText does not appear elsewhere in the input and is not considered a word.

// Output

// For each test case, output the words which occur n times in the input text, one word per line, lower case, in alphabetical order. If there are no such words in input, output the following line:

// There is no such word.
// Leave a blank line between cases.
// Samples

// input
// 2

// In practice, the difference between theory and practice is always
// greater than the difference between theory and practice in theory.
// 	- Anonymous

// Man will occasionally stumble over the truth, but most of the
// time he will pick himself up and continue on.
//         - W. S. L. Churchill
// EndOfText
// output
// between
// difference
// in
// will

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
        cin.ignore();
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
            cout << "There is no such word." << endl;
    }
}