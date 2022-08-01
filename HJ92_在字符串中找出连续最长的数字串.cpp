#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        string temp = "";
        vector<string> vec;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9') //找到数字字符串并加入到
            {
                temp += str[i];
                // cout << temp<<" ";

                if (str[i + 1] < '0' || str[i + 1] > '9' || i == str.length() - 1)
                {
                    vec.push_back(temp);
                    temp.clear();
                }
            }
        }

        vector<pair<string, int>> str_and_len;
        vector<int> veclen;
        for (int i = 0; i < vec.size(); i++) //统计每个数字字符串的长度
        {
            veclen.push_back(vec[i].length());
            str_and_len.push_back(make_pair(vec[i], vec[i].length()));
        }
        sort(veclen.begin(), veclen.end());
        reverse(veclen.begin(), veclen.end());

        int maxlen = veclen[0];
        int count = 0;
        for (int i = 0; i < veclen.size(); i++)
        {
            if (veclen[i] == maxlen)
            {
                count++;
            }
        }

        if (count == 1)
        {
            for (int i = 0; i < str_and_len.size(); i++)
            {
                if (str_and_len[i].second == maxlen)
                {
                    cout << str_and_len[i].first << "," << str_and_len[i].second << endl;
                }
            }
        }
        else
        {
            for (int i = 0; i < str_and_len.size(); i++)
            {
                if (str_and_len[i].second == maxlen)
                {
                    cout << str_and_len[i].first;
                }
            }
            cout << "," << maxlen << endl;
        }
    }

    return 0;
}
