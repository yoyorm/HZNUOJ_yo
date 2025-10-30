// Minesweeper
// Description
// Minesweeper Have you ever played Minesweeper? This cute little game comes with a certain operating system whose name we can't remember. The goal of the game is to find where all the mines are located within a M x N field. The game shows a number in a square which tells you how many mines there are adjacent to that square. Each square has at most eight adjacent squares. The 4 x 4 field on the left contains two mines, each represented by a ``*'' character. If we represent the same field by the hint numbers described above, we end up with the field on the right: *... .... .*.. .... *100 2210 1*10 1110
// Input
// The input will consist of an arbitrary number of fields. The first line of each field contains two integers n and m ( 0 < n, m<100) which stand for the number of lines and columns of the field, respectively. Each of the next n lines contains exactly m characters, representing the field. Safe squares are denoted by ``.'' and mine squares by ``*,'' both without the quotes. The first field line where n = m = 0 represents the end of input and should not be processed.
// Output
// For each field, print the message Field #x: on a line alone, where x stands for the number of the field starting from 1. The next n lines should contain the field with the ``.'' characters replaced by the number of mines adjacent to that square. There must be an empty line between field outputs.
// Samples
// input
// 4 4
// *...
// ....
// .*..
// ....
// 3 5
// **...
// .....
// .*...
// 0 0
// output
// Field #1:
// *100
// 2210
// 1*10
// 1110

// Field #2:
// **100
// 33200
// 1*100

#include <iostream>

using namespace std;
char bomb(char **s, int x, int y);
int main()
{
    int x, y;
    int n = 0;
    while (cin >> x >> y && x != 0 && y != 0)
    {
        n++;
        // 刻意多给二维数组多围起来一圈，简化后续扫描的算法
        char **s = new char *[x + 2];
        for (int i = 0; i <= x + 1; i++)
        {
            s[i] = new char[y + 2];
        }
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                cin >> s[i][j];
            }
        }
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (s[i][j] == '.')
                {
                    s[i][j] = bomb(s, i, j);
                }
            }
        }
        cout << "Field #" << n << ":" << endl;
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                cout << s[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}

char bomb(char **s, int x, int y)
// 上下左右全部扫一圈即可
{
    int num = 0;
    if (s[x - 1][y - 1] == '*')
        num++;
    if (s[x - 1][y] == '*')
        num++;
    if (s[x - 1][y + 1] == '*')
        num++;
    if (s[x][y - 1] == '*')
        num++;
    if (s[x][y + 1] == '*')
        num++;
    if (s[x + 1][y - 1] == '*')
        num++;
    if (s[x + 1][y] == '*')
        num++;
    if (s[x + 1][y + 1] == '*')
        num++;
    return num + '0';
}