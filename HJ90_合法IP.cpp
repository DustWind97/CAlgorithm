#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

//分割字符串
vector<string> splitstr(string str, char mark)
{
    vector<string> vec;
    string subStr;

    //遍历字符串，同时将i位置的字符放入到子串中，当遇到tag（需要切割的字符时）完成一次切割
    //遍历结束之后即可得到切割后的字符串数组
    for (size_t i = 0; i < str.length(); i++)
    {
        if (mark == str[i]) //完成一次切割
        {
            if (!subStr.empty())
            {
                vec.push_back(subStr);
                subStr.clear();
            }
        }
        else //将i位置的字符放入子串
        {
            subStr.push_back(str[i]);
        }
    }

    if (!subStr.empty()) //剩余的子串作为最后的子字符串
    {
        vec.push_back(subStr);
    }
    return vec;
}

// ip转化成比特流
string IP2BitStream(string ip)
{
    string bitstr; //比特流
    bitstr.clear();
    vector<string> vec;
    vec = splitstr(ip, '.'); //分割ip并存放各个元素到vec当中
    for (string str : vec)
    {
        int num = atoi(str.c_str());
        bitset<8> numbit;
        numbit = bitset<8>(num);
        bitstr += numbit.to_string();
    }
    return bitstr;
}

// ip合法性检测
bool ipcheck(string ip)
{
    //分段检测是否属于0-255范围
    vector<string> vec;
    vec = splitstr(ip, '.');
    if (vec.size() != 4)
    {
        return false;
    }
    for (string str : vec)
    {
        if (str[0] == '0' && str.length() > 1)
        {
            return false;
        }
        if (str[0] < '0' || str[0] > '9')
        {
            return false;
        }
    }
    for (string str : vec)
    {
        int num = atoi(str.c_str());
        if (num < 0 || num > 255)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str;
    while (cin >> str)
    {
        if (ipcheck(str))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
