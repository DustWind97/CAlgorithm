#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// cmp0和cmp1为排序规则
bool cmp0(pair<string, int> left, pair<string, int> right)
{
    // 0为从高到低
    return left.second > right.second;
}
bool cmp1(pair<string, int> left, pair<string, int> right)
{
    // 1为从低到高
    return left.second < right.second;
}

int main()
{
    int n; //输入n组数

    while (cin >> n)
    {
        int type;
        cin >> type;

        //录入n组数据
        vector<pair<string, int>> vec; //第一个参数为分数值，第二个参数为索引
        for (int i = 0; i < n; i++)
        {
            string name = "";
            int score = 0;
            cin >> name >> score;
            vec.push_back(make_pair(name, score)); // i为索引,temp_num为成绩
        }

        //对vec进行处理
        if (type == 0) //降序输出
        {
            stable_sort(vec.begin(), vec.end(), cmp0);
        }
        else if (type == 1) //升序输出
        {
            stable_sort(vec.begin(), vec.end(), cmp1);
        }

        //输出结果
        for (auto elem : vec)
        {
            cout << elem.first << " " << elem.second << endl;
        }
    }

    return 0;
}
