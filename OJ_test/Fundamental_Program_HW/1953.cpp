// Description
//
// �и�Ⱥ���Ұ�˯������������ֻ��ÿ�����϶���˵�����Ϻ�������硱��Ȼ���ж仨���Ŷ��ͻ�˵�����Ϻ�������硱������ĳֻ�ͻ�ȥ�ƻ����Ρ�ÿ�����������ܳɹ��ƻ����Ρ������һ�����ɹ��ƻ��˶��Σ����ʵ�n�����ܲ��ܳɹ��ƻ����Σ�
//
// Input
//
// ��һ������һ��T����ʾ��T��������ݡ���0 < T <= 10000)
//	ÿ��������ݵ�һ������һ��n�������n�졣(0 < n <= 1000, 000, 000)
//
//	Output
//
//	����ÿ���������һ���ַ��������ĳֻ�ɹ��ƻ��˶��Σ��������showshowshow��; ���������forever love��.

#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    int temp = 0;
    for (int i = 0; i < T; i++)
    {
        cin >> temp;
        if (temp % 3 == 1)
        {
            cout << "showshowshow\n";
        }
        else
        {
            cout << "forever love\n";
        }
    }

    return 0;
}
