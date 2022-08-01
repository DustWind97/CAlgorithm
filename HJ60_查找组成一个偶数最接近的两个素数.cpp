#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <map>

using namespace std;

//是否素数
bool IsPrime(int num)
{
    if (num <= 1)
        return false;
    else if (num == 2 || num == 3)
        return true;
    else
    {
        for (int i = 2; i < sqrt(num) + 1; i++)
        {
            if ((num % i) == 0)
                return false;
        }
    }
    return true;
}

int main()
{
    int num;
    while (cin >> num)
    {
        vector<int> vec; //用来存储比num小的所有素数
        //找比它小的所有素数
        for (int i = 2; i < num; i++)
        {
            //如果是素数
            if (IsPrime(i) == true)
            {
                vec.push_back(i);
            }
        }
        //找到所有满足first + second = num的素数
        vector<pair<int, int>> group;
        int count = 0; //找到满足情况的组数
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = i; j < vec.size(); j++)
            {
                if (vec[i] + vec[j] == num) // vec[j]一定是大于等于vec[i]的
                {
                    group.push_back(make_pair(vec[i], vec[j]));
                    count++;
                }
            }
        }

        // for (int i = 0; i < group.size(); i++)
        // {
        //     cout << group[i].first << " | " << group[i].second << endl;
        // }

        //输出差值最小的一组
        // vector<int> differ;
        // for (auto elem : group)
        // {
        //     differ.push_back(elem.second - elem.first);
        // }
        // sort(differ.begin(), differ.end());

        // int min = differ[0]; //找到最小的

        // for (auto elem : group)//线性数组，顺序遍历，找到的一定是第一个
        // {
        //     if (elem.second - elem.first == min) //找到差值最小的一组
        //     {
        //         cout << elem.first << endl;
        //         cout << elem.second << endl;
        //     }
        // }
        int min_i = 0;
        int min_differ = 1000000;
        for (int i = 0; i < group.size(); i++)
        {
            if (group[i].second - group[i].first < min_differ)
            {
                min_differ = group[i].second - group[i].first;
                min_i = i;
            }
        }

        cout << group[min_i].first << endl;
        cout << group[min_i].second << endl;
    }

    return 0;
}