/*
内置函数
islower(char c) 是否为小写字母
isuppper(char c) 是否为大写字母
isdigit(char c) 是否为数字
isalpha(char c) 是否为字母
isalnum(char c) 是否为字母或者数字
toupper(char c) 字母小转大
tolower(char c) 字母大转小
*/

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// 1.长度超过8位
bool check1(string str)
{
    return str.length() > 8;
}

// 2.包括大小写字母.数字.其它符号,以上四种至少三种
bool check2(string str)
{
    int type[4] = {0};
    for (auto iter = str.begin(); iter != str.end(); iter++)
    {
        if (*iter >= 'a' && *iter <= 'z') //小写字母
        {
            type[0] = 1;
        }
        else if (*iter >= 'A' && *iter <= 'Z') //大写字母
        {
            type[1] = 1;
        }
        else if (*iter >= '0' && *iter <= '9') //数字
        {
            type[2] = 1;
        }
        else //其他符号
        {
            type[3] = 1;
        }
    }
    int rt = type[0] + type[1] + type[2] + type[3];
    return rt >= 3;
}

// 3.不能有长度大于2的包含公共元素的子串重复 （注：其他符号不含空格或换行）---------------（注意分割子串substr和find函数的使用）
bool check3(string str)
{
    unordered_set<std::string> sets;
    string tmp;
    for (int i = 0; i < str.length() - 2; ++i)
    {
        tmp = str.substr(i, 3);
        if (sets.find(tmp) == sets.end())//sets当中没有该元素就添加
        {
            sets.insert(tmp);
        }
        else//一旦有，则返回false
        {
            return false;
        }
    }
    return true;//遍历完都没有大于2的公共元素子串
}

//密码验证合格
int main()
{
    string input;

    //汇总输入条件
    while (cin >> input)
    {
        if (check1(input) && check2(input) && check3(input))
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << "NG" << endl;
        }
    }

    return 0;
}