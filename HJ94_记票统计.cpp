#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    while (cin >> n)
    {
        map<string, int> dict; //用来统计票数
        vector<string> vec;    //存放输入的待统计名字

        //记录待统计名字
        for (int i = 0; i < n; i++)
        {
            string temp = "";
            cin >> temp;
            vec.push_back(temp);
        }

        //记录总票数
        int num;
        cin >> num;

        //记录总票数与候选人的映射关系
        for (int i = 0; i < num; i++)
        {
            string temp = "";
            cin >> temp;
            ++dict[temp]; //统计合法以及非法的票数
        }

        //筛查出人数
        int counter = 0; //合法人数
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " : " << dict[vec[i]] << endl;
            counter += dict[vec[i]];
        }
        cout << "Invalid : " << (num - counter) << endl;
    }

    return 0;
}