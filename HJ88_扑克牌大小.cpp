#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
大小规则:
    个子、对子、三个比较牌面大小；
    顺子比较最小牌大小；
    炸弹大于前面所有的牌，炸弹之间比较牌面大小；
    对王是最大的牌；
*/

//用哈希表记录每个字符相应的大小，其中10用字符D表示,joker用g表示，JOKER用G表示
unordered_map<char, int> nums = {
    //键为牌面字符 值为其优先级大小（值越大优先级越高）
    {'3', 1},
    {'4', 2},
    {'5', 3},
    {'6', 4},
    {'7', 5},
    {'8', 6},
    {'9', 7},
    {'D', 8}, //将10改成一个字母D来代替
    {'J', 9},
    {'Q', 10},
    {'K', 11},
    {'A', 12},
    {'2', 13},
    {'g', 14}, //将joker转换成字母g
    {'G', 15}, //将JOKER转换成字母G
};

//封装一个牌面转换---将所有牌面都转换成一个字母
string Change(string &str_origin)
{
    string str = "";
    if (str_origin.find("joker") != string::npos) //找到小王--注意大小王只能出现一次
    {
        return "g";
    }
    else if (str_origin.find("JOKER") != string::npos) //找到大鬼--注意大小王只能出现一次
    {
        return "G";
    }
    else
    {
        for (int i = 0; i < str_origin.length(); i++)
        {
            if (str_origin[i] == '1' && str_origin[i + 1] == '0')
            {
                str += "D"; //把10改成一个字母D表示
                i++;        //跳过字母0
            }
            else
            {
                str += str_origin[i];
            }
        }
    }

    return str;
}

int main()
{
    string str; //获取原始字符串
    while (getline(cin, str))
    {
        string s1_origin = str.substr(0, str.find("-"));
        string s2_origin = str.substr(str.find("-") + 1, str.length() - str.find("-"));
        // cout << s1 << " | " << s2 << endl;
        string s1 = "", s2 = "";
        s1 = Change(s1_origin);
        s2 = Change(s2_origin);

        // cout << s1 << " | " << s2 << endl;

        if (s1_origin == "joker JOKER" || s2_origin == "joker JOKER") //如果有王炸直接输出王炸
        {
            cout << "joker JOKER" << endl;
        }
        else if (s1.length() == 7) //第一个为炸弹
        {
            cout << s1_origin << endl;
        }
        else if (s2.length() == 7) //第二个为炸弹
        {
            cout << s2_origin << endl;
        }
        else if (s1.length() == s2.length())
        {
            if (s1.length() == 7 && s2.length() == 7) //长度为7是因为牌面为长度1，空格为长度1  都为炸弹
            {
                if (nums[s1[0]] > nums[s2[0]])
                {
                    cout << s1_origin << endl;
                }
                else
                {
                    cout << s2_origin << endl;
                }
            }
            else //顺子,个子，对子，三个比大小
            {
                if (nums[s1[0]] > nums[s2[0]])
                {
                    cout << s1_origin << endl;
                }
                else
                {
                    cout << s2_origin << endl;
                }
            }
        }
        else
        {
            cout << "ERROR" << endl;
        }
    }

    return 0;
}