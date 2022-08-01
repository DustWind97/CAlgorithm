#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//统计字符串中的CG个数；
int TongJi(string str)
{
    int num = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'C' || str[i] == 'G')
        {
            num++;
        }
    }
    return num;
}

int main()
{
    string str; // DNA序列
    int len;    //子串长度

    while (cin >> str >> len)
    {
        //先将str按长度len划分成若干子串
        vector<string> vec;
        for (int i = 0; i <= str.length() - len; i++)
        {
            string temp = "";
            temp = str.substr(i, len);
            vec.push_back(temp);
            temp.clear();
        }

        // for (int i = 0; i < vec.size(); i++)
        // {
        //     cout << vec[i] << endl;
        // }

        int max_ratio = 0;
        string max_ratio_str = "";
        for (int i = 0; i < vec.size(); i++)
        {
            int ratio = TongJi(vec[i]); //统计第i个子串的CG比例
            if (max_ratio < ratio)
            {
                max_ratio_str.clear();
                max_ratio_str = vec[i];
                max_ratio = ratio;
            }
        }

        cout << max_ratio_str << endl;
    }

    return 0;
}