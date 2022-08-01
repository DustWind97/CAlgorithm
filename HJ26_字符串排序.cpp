//局部交换才能避免大写和小写乱序的问题
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//是否英文字符
bool isChar(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return true;
    }
    return false;
}

int main()
{
    string str;
    while (getline(cin, str))
    {
        //对字符串进行排序
        vector<int> ch;
        for (int i = 0; i < str.length(); i++)
        {
            if (isChar(str[i]))//记录所有字母的下标
            {
                ch.push_back(i);
            }
        }

        //对ch进行排序
        for (int i = 0; i < ch.size() - 1; i++)
        {
            for (int j = 0; j < ch.size() - i - 1; j++)
            {
                // char t1 = str[ch[j]]; //相邻的作比较
                // char t2 = str[ch[j + 1]];

                // //将两个转换成大写
                // if (t1 >= 'a' && t1 <= 'z')
                //     t1 = t1 - 'a' + 'A';
                // if (t2 >= 'a' && t2 <= 'z')
                //     t2 = t2 - 'a' + 'A';
                // if (t1 > t2)
                // {
                //     // cout << i << ":" << ch[i] << "交换" << j << ":" << ch[j] << endl;
                //     char temp = str[ch[j]];
                //     str[ch[j]] = str[ch[j + 1]];
                //     str[ch[j + 1]] = temp;
                // }
                if (tolower(str[ch[j]]) > tolower(str[ch[j + 1]]))
                {
                    char temp = str[ch[j]];
                    str[ch[j]] = str[ch[j + 1]];
                    str[ch[j + 1]] = temp;
                }
            }
        }

        cout << str << endl;
    }

    return 0;
}