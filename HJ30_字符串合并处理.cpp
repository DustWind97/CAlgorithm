#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// 0-9，a-f的映射处理
int Char2Num(char ch)
{
    int num;
    if (ch >= '0' && ch <= '9')
    {
        num = ch - '0';
    }
    else if (ch >= 'a' && ch <= 'f')
    {
        num = ch - 'a' + 10;
    }
    else if (ch >= 'A' && ch <= 'F')
    {
        num = ch - 'A' + 10;
    }
    return num;
}

// 0-15映射为字符
char Num2Char(int num)
{
    char ch;
    if (num >= 0 && num <= 9)
    {
        ch = num + '0';
    }
    else if (num >= 10 && num <= 15)
    {
        ch = num - 10 + 'A';
    }
    return ch;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2; //输入dec fab---->decfab---->偶数dca,奇数efb---->排序acd,bef---->abcedf
    //第一步，合并字符串
    string str = str1 + str2;
    // cout << str << endl;
    vector<char> odd, even;
    //然后分奇偶
    for (int i = 0; i < str.length(); i++)
    {
        if (i % 2 == 0)
        {
            even.push_back(str[i]);
        }
        else if (i % 2 == 1)
        {
            odd.push_back(str[i]);
        }
    }
    //第二步，对odd和even进行重新排序
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    // //打印查看odd
    // for (vector<char>::iterator it = odd.begin(); it != odd.end(); it++)
    // {
    //     cout << *it;
    // }
    // cout << endl;
    // //打印查看even
    // for (vector<char>::iterator it = even.begin(); it != even.end(); it++)
    // {
    //     cout << *it;
    // }
    // cout << endl;
    //再将两个字符串合并
    string sorted;
    for (int i = 0; i < odd.size() + even.size(); i++)
    {
        if (i % 2 == 0)
        {
            sorted += even[i / 2];
        }
        else if (i % 2 == 1)
        {
            sorted += odd[i / 2];
        }
    }

    //cout << sorted << endl;

    //第三步，对排序后的字符串中的'0'~'9'、'A'~'F'和'a'~'f'字符
    for (int i = 0; i < sorted.length(); i++)
    {
        if ((sorted[i] >= '0' && sorted[i] <= '9') || (sorted[i] >= 'a' && sorted[i] <= 'f') || (sorted[i] >= 'A' && sorted[i] <= 'F'))
        {
            int numfrom;
            numfrom = Char2Num(sorted[i]);
            // cout << numfrom << endl;
            bitset<4> numbit;
            numbit = bitset<4>(numfrom);
            // cout << numbit << endl;
            string bitstream = numbit.to_string();
            reverse(bitstream.begin(), bitstream.end());
            // cout<<bitstream<<endl;
            int numto = stoi(bitstream, 0, 2); //将二进制字符串转换成十进制数
            // cout<<numto<<endl;
            cout << Num2Char(numto); //-----最后一步有问题
        }
        else
        {
            cout << sorted[i];
        }
    }

    return 0;
}