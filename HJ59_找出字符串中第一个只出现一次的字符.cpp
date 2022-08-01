#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

//统计字符串中某个字符的个数
int Count(string str, char ch)
{
    int counter = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ch)
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    string str;
    cin >> str;

    // map<char, int> dict;
    // string temp; //顺序存放不重复字符
    // temp.clear();

    // //将字符串元素添加到字典中
    // for (int i = 0; i < str.length(); i++)
    // {
    //     ++dict[str[i]];
    // }

    // for (int i = 0; i < str.length(); i++)
    // {
    //     int counter = Count(str, str[i]);
    //     if (temp.find(str[i]) == string::npos) //未找到
    //     {
    //         temp += str[i];
    //         // temp_num.push_back(counter);
    //     }
    //     else //找到
    //     {
    //         continue;
    //     }
    // }

    // int flag = 1; //定义一个未找到的标志
    // for (int i = 0; i < temp.length(); i++)
    // {
    //     if (dict[temp[i]] == 1) //找到就返回此字符并结束循环
    //     {
    //         cout << temp[i] << endl;
    //         flag = 0;
    //         break;
    //     }
    // }
    // if (flag)
    // {
    //     cout << "-1" << endl; //如果for循环执行完毕都没有输出则未找到
    // }

    string str_unique = str;

    str_unique.erase(unique(str_unique.begin(), str_unique.end()), str_unique.end()); //删除重复元素

    //cout << str_unique << endl;
    int flag = 1; //定义一个未找到的标志
    for (int i = 0; i < str_unique.length(); i++)
    {
        //在str中统计第一个只出现一次的字符
        if (count(str.begin(), str.end(), str_unique[i]) == 1)
        {
            cout << str_unique[i] << endl;
            flag = 0; //已经找到，后续不执行下一个if语句
            break;
        }
    }
    if (flag)
    {
        cout << "-1" << endl; //如果for循环执行完毕都没有输出则未找到
    }

    return 0;
}