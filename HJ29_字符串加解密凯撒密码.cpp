#include <iostream>
#include <string>

using namespace std;

//加密算法
void Encode(string str)
{
    string output;
    for (int i = 0; i < str.length(); i++)
    {
        //小写字母
        if (str[i] >= 'a' && str[i] <= 'y') // a-y
        {
            char temp;
            temp = str[i] + 1;
            output += toupper(temp);
        }
        else if (str[i] == 'z') // z
        {
            output += 'A';
        }
        //大写字母
        else if (str[i] >= 'A' && str[i] <= 'Y') // A-Y
        {
            char temp;
            temp = str[i] + 1;
            output += tolower(temp);
        }
        else if (str[i] == 'Z') // Z
        {
            output += 'a';
        }
        //数字
        else if (str[i] >= '0' && str[i] <= '8') // 0-8
        {
            char temp;
            temp = str[i] + 1;
            output += temp;
        }
        else if (str[i] == '9') // 9
        {
            output += '0';
        }
    }
    cout << output << endl;
}

//解密算法
void Decode(string str)
{
    string output;
    for (int i = 0; i < str.length(); i++)
    {
        //小写字母
        if (str[i] >= 'b' && str[i] <= 'z') // b-z
        {
            char temp;
            temp = str[i] - 1;
            output += toupper(temp);
        }
        else if (str[i] == 'a') // a
        {
            output += 'Z';
        }
        //大写字母
        else if (str[i] >= 'B' && str[i] <= 'Z') // B-Z
        {
            char temp;
            temp = str[i] - 1;
            output += tolower(temp);
        }
        else if (str[i] == 'A') // A
        {
            output += 'z';
        }
        //数字
        else if (str[i] >= '1' && str[i] <= '9') // 1-9
        {
            char temp;
            temp = str[i] - 1;
            output += temp;
        }
        else if (str[i] == '0') // 0
        {
            output += '9';
        }
    }
    cout << output << endl;
}

int main()
{
    string first_row, second_row;
    cin >> first_row >> second_row;

    Encode(first_row);
    Decode(second_row);

    return 0;
}