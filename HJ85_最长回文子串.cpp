#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*也可以用中心扩展法*/
bool Check(string str) //判定是否回文串
{
    bool rt;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != str[str.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str;
    while (getline(cin, str)) //输入一个只含小写字母的字符串
    {
        //首先处理字符串，得到所有长度的子串
        vector<string> vec;
        for (int i = 2; i <= str.length(); i++) //子串
        {
            for (int j = 0; j <= str.length() - i; j++)
            {
                string temp = "";
                temp = str.substr(j, i);
                vec.push_back(temp);
                // cout << temp << " ";
            }
        }

        //遍历vec得到最长回文串
        int maxlen = 0;
        string maxstr = "";
        for (int i = 0; i < vec.size(); i++)
        {
            if (Check(vec[i]) == true) //第i个是回文字符串
            {
                if (maxlen < vec[i].length())
                {
                    maxstr.clear();
                    maxlen = vec[i].length();
                    maxstr = vec[i];
                }
            }
        }

        cout << maxlen << endl;
    }

    return 0;
}