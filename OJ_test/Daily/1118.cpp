// Description

// 在大学里，很多单词都是一词多义，偶尔在文章里还要用引申义。这困扰Redraiment很长的时间。

// 他开始搜集那些单词的所有意义。他发现了一些规律，例如

// “a”能用“e”来代替, “c”能用“f”来代替……

// 现在他给出了字母的替换规则，如下所示，A被E替换，B被C替换，依次类推。

// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
// E C F A J K L B D G H I V W Z Y M N O P Q R S T U X
// a b c d e f g h i j k l m n o p q r s t u v w x y z
// e r w q t y g h b n u i o p s j k d l f a z x c v m

// Input

// 本题包括多组测试数据。 每组测试数据为一行：为仅由字母和空格组成的字符串(空格不变)。 输入以单行“#”结束。

// Output

// 对应每组测试数据，替换后输出它的引申义。
// Samples

// input 
// Ilttabaje zaujljg
// #
// output 
// Different meaning

#include <iostream>
#include <cstring>
using namespace std;
void verify(string &data, int pos);
string test = "ECFAJKLBDGHIVWZYMNOPQRSTUXerwqtyghbnuiopsjkdlfazxcvm";
int main()
{

    string data;
    while (getline(cin,data) && data != "#")
    {
        for (int i = 0; i < data.size(); i++)
        {
            verify(data, i);
        }
        cout << data << endl;
    }
}

void verify(string &data, int pos)
{
    switch (data[pos] - 'A')
    {
    case 0:
        data[pos] = test[0];
        break;
    case 1:
        data[pos] = test[1];
        break;
    case 2:
        data[pos] = test[2];
        break;
    case 3:
        data[pos] = test[3];
        break;
    case 4:
        data[pos] = test[4];
        break;
    case 5:
        data[pos] = test[5];
        break;
    case 6:
        data[pos] = test[6];
        break;
    case 7:
        data[pos] = test[7];
        break;
    case 8:
        data[pos] = test[8];
        break;
    case 9:
        data[pos] = test[9];
        break;
    case 10:
        data[pos] = test[10];
        break;
    case 11:
        data[pos] = test[11];
        break;
    case 12:
        data[pos] = test[12];
        break;
    case 13:
        data[pos] = test[13];
        break;
    case 14:
        data[pos] = test[14];
        break;
    case 15:
        data[pos] = test[15];
        break;
    case 16:
        data[pos] = test[16];
        break;
    case 17:
        data[pos] = test[17];
        break;
    case 18:
        data[pos] = test[18];
        break;
    case 19:
        data[pos] = test[19];
        break;
    case 20:
        data[pos] = test[20];
        break;
    case 21:
        data[pos] = test[21];
        break;
    case 22:
        data[pos] = test[22];
        break;
    case 23:
        data[pos] = test[23];
        break;
    case 24:
        data[pos] = test[24];
        break;
    case 25:
        data[pos] = test[25];
        break;
    case 32: // 把大小写之间的其他字符跳过
        data[pos] = test[26];
        break;
    case 33:
        data[pos] = test[27];
        break;
    case 34:
        data[pos] = test[28];
        break;
    case 35:
        data[pos] = test[29];
        break;
    case 36:
        data[pos] = test[30];
        break;
    case 37:
        data[pos] = test[31];
        break;
    case 38:
        data[pos] = test[32];
        break;
    case 39:
        data[pos] = test[33];
        break;
    case 40:
        data[pos] = test[34];
        break;
    case 41:
        data[pos] = test[35];
        break;
    case 42:
        data[pos] = test[36];
        break;
    case 43:
        data[pos] = test[37];
        break;
    case 44:
        data[pos] = test[38];
        break;
    case 45:
        data[pos] = test[39];
        break;
    case 46:
        data[pos] = test[40];
        break;
    case 47:
        data[pos] = test[41];
        break;
    case 48:
        data[pos] = test[42];
        break;
    case 49:
        data[pos] = test[43];
        break;
    case 50:
        data[pos] = test[44];
        break;
    case 51:
        data[pos] = test[45];
        break;
    case 52:
        data[pos] = test[46];
        break;
    case 53:
        data[pos] = test[47];
        break;
    case 54:
        data[pos] = test[48];
        break;
    case 55:
        data[pos] = test[49];
        break;
    case 56:
        data[pos] = test[50];
        break;
    case 57:
        data[pos] = test[51];
        break;
    }
}
