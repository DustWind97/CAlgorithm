#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

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

//将点分十进制IP转换成一个十进制
long IP2Dec(string ip)
{
    string dec;
    dec.clear();
    vector<string> vec;
    vec = splitstr(ip, '.'); //分割ip并存放各个元素到vec当中
    for (string str : vec)
    {
        // cout << str << endl; // vector中存放了分割后的元素
        int num = atoi(str.c_str());
        bitset<8> numbit;
        numbit = bitset<8>(num);
        dec += numbit.to_string();
    }
    return stol(dec, 0, 2);
}

//将一个十进制数转换成一个点分十进制IP
string Dec2IP(long dec)
{
    string ip;
    bitset<32> numbit;
    numbit = bitset<32>(dec);
    string str = numbit.to_string();
    //cout << str << endl;
    string spart1, spart2, spart3, spart4;
    int npart1, npart2, npart3, npart4;

    spart1 = str.substr(0, 8);
    npart1 = stoi(spart1, 0, 2);
    //cout << spart1 << endl;

    spart2 = str.substr(8, 8);
    npart2 = stoi(spart2, 0, 2);
    //cout << spart2 << endl;


    spart3 = str.substr(16, 8);
    npart3 = stoi(spart3, 0, 2);
    //cout << spart3 << endl;

    spart4 = str.substr(24, 8);
    npart4 = stoi(spart4, 0, 2);
    //cout << spart4 << endl;

    ip = to_string(npart1) + '.' + to_string(npart2) + '.' + to_string(npart3) + '.' + to_string(npart4);

    return ip;
}

int main()
{
    string ip, dec;
    cin >> ip >> dec;

    //执行第一部分
    long ip2dec;
    ip2dec = IP2Dec(ip);
    cout << ip2dec << endl;

    //执行第二部分
    string dec2ip;
    dec2ip = Dec2IP(atol(dec.c_str()));
    cout << dec2ip << endl;

    return 0;
}
