#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<vector<int>> vec(n);
        int count = 0, num = 0;
        for (int i = 0; i < n; i++)//第i行有count个数据
        {
            //第几次
            count++;
            for (int j = 0; j < count; j++)
            {
                num++;
                vec[i].push_back(num);
                // cout << num << " ";
            }
            // cout << endl;
        }

        //遍历vec，将vec重新整理
        int count_out = 0;
        for (int i = 0; i < n; i++)
        {
            count_out++;
            reverse(vec[i].begin(), vec[i].end());
        }

        for (int j = 0; j < n; j++)
        {
            for (size_t i = j; i < n; i++)
            {
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}