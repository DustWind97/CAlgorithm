#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//小写字母与数字的转换
char change(char ch)
{
    char strtemp;
    if (ch == 'a' || ch == 'b' || ch == 'c') // abc----2
    {
        strtemp += '2';
    }
    else if (ch == 'd' || ch == 'e' || ch == 'f') // def----3
    {
        strtemp += '3';
    }
    else if (ch == 'g' || ch == 'h' || ch == 'i') // ghi----4
    {
        strtemp += '4';
    }
    else if (ch == 'j' || ch == 'k' || ch == 'l') // jkl----5
    {
        strtemp += '5';
    }
    else if (ch == 'm' || ch == 'n' || ch == 'o') // mno----6
    {
        strtemp += '6';
    }
    else if (ch == 'p' || ch == 'q' || ch == 'r' || ch == 's') // pqrs----7
    {
        strtemp += '7';
    }
    else if (ch == 't' || ch == 'u' || ch == 'v') // tuv----8
    {
        strtemp += '8';
    }
    else if (ch == 'w' || ch == 'x' || ch == 'y' || ch == 'z') // wxyz----9
    {
        strtemp += '9';
    }

    return strtemp;
}

int main()
{
    string str;
    cin >> str;
    string strtemp;
    strtemp.clear();

    //对字符串进行处理
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1') // 1----1
        {
            strtemp += '1';
        }
        else if (str[i] == '0') // 0----0
        {
            strtemp += '0';
        }
        else if (str[i] >= 'a' && str[i] <= 'z') //如果是小写字母进行下一步处理
        {
            strtemp += change(str[i]);
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') //如果是大写字母进行下一步处理
        {
            char tempch;
            if (str[i] == 'Z')
            {
                tempch = 'a';
            }
            else
            {
                tempch = tolower(str[i]);
                tempch += 1;
            }
            strtemp += tempch;
        }
        else
        {
            strtemp += str[i];
        }
    }
    cout << strtemp;
    return 0;
}