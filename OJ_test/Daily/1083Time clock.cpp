// Time
// Description
// Digital clock use 4 digits to express time, each digit is described by 3*3 characters (including”|”,”_”and” “). Now given the current time, please tell us how can it be expressed by the digital clock.
// Input
// There are several test cases.
// Each case contains 4 integers in a line, separated by space.
// Proceed to the end of file.
// Output

// For each test case, output the time expressed by the digital clock such as Sample Output.
// Samples
// input
// 1 2 5 6
// 2 3 4 2
// output
//     _  _  _
//   | _||_ |_
//   ||_  _||_|
//  _  _     _
//  _| _||_| _|
// |_  _|  ||_
// Hint

// The digits showed by the digital clock are as follows:
//    _  _     _  _  _  _  _  _
//  | _| _||_||_ |_   ||_||_|| |
//  ||_  _|  | _||_|  ||_| _||_|

#include <iostream>

#include <string>
using namespace std;
void fill(string *show, int x);
int main()
{
    int a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        string show[3] = {"", "", ""};
        fill(show, a);
        fill(show, b);
        fill(show, c);
        fill(show, d);
        cout << show[0] << endl;
        cout << show[1] << endl;
        cout << show[2] << endl;
    }
}

void fill(string *show, int x)
{
    switch (x)
    {
    case 1:
    {
        show[0] += "   ";
        show[1] += "  |";
        show[2] += "  |";
    }
    break;
    case 2:
    {
        show[0] += " _ ";
        show[1] += " _|";
        show[2] += "|_ ";
    }
    break;
    case 3:
    {
        show[0] += " _ ";
        show[1] += " _|";
        show[2] += " _|";
    }
    break;
    case 4:
    {
        show[0] += "   ";
        show[1] += "|_|";
        show[2] += "  |";
    }
    break;
    case 5:
    {
        show[0] += " _ ";
        show[1] += "|_ ";
        show[2] += " _|";
    }
    break;
    case 6:
    {
        show[0] += " _ ";
        show[1] += "|_ ";
        show[2] += "|_|";
    }
    break;
    case 7:
    {
        show[0] += " _ ";
        show[1] += "  |";
        show[2] += "  |";
    }
    break;
    case 8:
    {
        show[0] += " _ ";
        show[1] += "|_|";
        show[2] += "|_|";
    }
    break;
    case 9:
    {
        show[0] += " _ ";
        show[1] += "|_|";
        show[2] += " _|";
    }
    break;
    case 0:
    {
        show[0] += " _ ";
        show[1] += "| |";
        show[2] += "|_|";
    }
    }
}