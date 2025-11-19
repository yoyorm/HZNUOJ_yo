
// https://www.luogu.com.cn/problem/P1518
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
bool search(const pair<int, int> &Fpos, const pair<int, int> &Cpos);
void move(const vector<vector<string>> &v, pair<int, int> &pos, string dir, char c);

string Fdir = "U";
string Cdir = "U";
int count = 0;
int main()
{
    vector<vector<string>> v(10, vector<string>(10));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            char ch;
            cin >> ch;
            v[i][j] = ch;
        }
    }

    pair<int, int> Fpos, Cpos;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (v[i][j] == "F")
                Fpos = make_pair(i, j);
            if (v[i][j] == "C")
                Cpos = make_pair(i, j);
        }
    }

    while (search(Fpos, Cpos) && count <= 10000)
    {
        move(v, Fpos, Fdir, 'F');
        move(v, Cpos, Cdir, 'C');
        count++;
    }
    if (count > 10000)
        count = 0;
    cout << count;
}

bool search(const pair<int, int> &Fpos, const pair<int, int> &Cpos)
{
    if (Fpos == Cpos)
        return false;
    return true;
}

void move(const vector<vector<string>> &v, pair<int, int> &pos, string dir, char c)
{
    int x = pos.first;
    int y = pos.second;
    if (dir == "U")
    {
        if (x - 1 != -1 && v[x - 1][y] != "*")
        {
            pos.first = x - 1;
        }
        else
        {
            if (c == 'C')
                Cdir = "R";
            else
                Fdir = "R";
        }
    }
    else if (dir == "D")
    {
        if (x + 1 != 10 && v[x + 1][y] != "*")
        {
            pos.first = x + 1;
        }
        else
        {
            if (c == 'C')
                Cdir = "L";
            else
                Fdir = "L";
        }
    }
    else if (dir == "L")
    {
        if (y - 1 != -1 && v[x][y - 1] != "*")
        {
            pos.second = y - 1;
        }
        else
        {
            if (c == 'C')
                Cdir = "U";
            else
                Fdir = "U";
        }
    }
    else if (dir == "R")
    {
        if (y + 1 != 10 && v[x][y + 1] != "*")
        {
            pos.second = y + 1;
        }
        else
        {
            if (c == 'C')
                Cdir = "D";
            else
                Fdir = "D";
        }
    }
}
