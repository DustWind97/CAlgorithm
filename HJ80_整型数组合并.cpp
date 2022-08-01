#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cin >> m;
    //输入第一个数组的数值
    vector<int> vec1;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        vec1.push_back(temp);
    }

    cin >> n;
    //输入第二个数组的数值
    vector<int> vec2;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec2.push_back(temp);
    }

    //得到新的vec
    vector<int> vec;
    vec.insert(vec.end(),vec1.begin(),vec1.end());
    vec.insert(vec.end(),vec2.begin(),vec2.end());
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());//用find写出来不对
    // for (int i = 0; i < vec2.size(); i++) //遍历vec2
    // {
    //     if (find(0, (int)vec1.size(), vec2[i]) == -1) //没有找到返回-1
    //     {
    //         vec.push_back(vec2[i]);
    //     }
    // }

    
    for (auto elem : vec)
    {
        cout << elem;
    }
    cout << endl;
    return 0;
}