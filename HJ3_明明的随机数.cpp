#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//思路：接收一个字符串，然后反向查找第一个空格
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }

        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end()); //去除不唯一的数

        for (auto elem : vec)
        {
            cout << elem << endl;
        }
    }

    return 0;
}