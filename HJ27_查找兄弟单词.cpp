#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n) //输入n
    {
        vector<string> vec(n); //输入n个字符串
        for (int i = 0; i < n; i++)//录入n个元素的字符串数组
        {
            string temp = "";
            cin >> temp;
            vec.push_back(temp);
        }

        string x; //输入要查找的单词
        cin >> x;

        int k; //按字典序排列后的第 k 个单词
        cin >> k;

        string input_str = x;
        sort(input_str.begin(), input_str.end());
        vector<string> vec_compare = vec;

        vector<string> vec_bro; //满足要求的兄弟单词

        for (int i = 0; i < vec_compare.size(); i++) //统计兄弟单词
        {
            if (vec_compare[i] == x) //不包含本身
            {
                continue;
            }
            sort(vec_compare[i].begin(), vec_compare[i].end());
            if (vec_compare[i] == input_str)
            {
                vec_bro.push_back(vec[i]);
            }
        }

        cout << vec_bro.size() << endl; //输出显示兄弟单词的个数

        //找到满足要求的兄弟单词
        //先对兄弟单词vec_bro进行字典排序
        sort(vec_bro.begin(), vec_bro.end());
        //然后找到第k个
        if (k < vec_bro.size())
        {
            cout << vec_bro[k-1] << endl;
        }
    }

    return 0;
}