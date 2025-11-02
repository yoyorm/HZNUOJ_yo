#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        short n1, n2, n3;
        char o1, o2;
        cin >> n1 >> o1 >> n2 >> o2 >> n3;
    }
}

int op(const char &op, int a, int b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '%':
        return a % b;
    }
}