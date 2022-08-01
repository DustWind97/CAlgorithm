#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        //保持最短串永远是str1
        if (str1.length() > str2.length())
        {
            string temp = str1;
            str1.clear();
            str1 = str2;
            str2.clear();
            str2 = temp;
        }

        vector<string> vec; //保存str1的所有子串
        for (int i = 2; i < str1.length(); i++)
        {
            for (int j = 0; j <= str1.length() - i; j++)
            {
                string temp = "";
                temp = str1.substr(j, i);
                vec.push_back(temp);
            }
        }

        int maxlen = 0;
        string maxstr;
        // for (auto elem : vec)
        // {
        //     // cout << elem << endl;
        //     if (str2.find(elem) != string::npos) //找到
        //     {
        //         maxlen = max(maxlen, (int)elem.length());
        //         maxstr.clear();
        //         maxstr = elem;
        //     }
        // }
        /*
        nvlrzqcjltmrejybjeshffenvkeqtbs nlo coyaokdpuxutrsmcmoearsgttgyyucgz gcn urfbubgvbwpyslaeykqhaaveqxijc
        wkigrnngxehuiwxrextitnmjykimyhcbxildpnmrf gcn evjyvwzwuzrwvlom nlo gbptornsybimbtnyhlmfecscmojrxekqmj
        */

        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << endl;
            if (str2.find(vec[i]) != string::npos) //找到
            {
                if (vec[i].length() > maxlen)
                {
                    maxlen = vec[i].length();
                    maxstr.clear();
                    maxstr = vec[i];
                }
            }
        }

        cout << maxstr << endl;
    }

    return 0;
}