#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

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

        //定义一个n+1长度的DP数组,初始赋值均为1-----------DP数组用于保存最长步数
        vector<int> DP(n, 1);
        int res = 0;
        for (int i = 0; i < vec.size(); i++) //遍历vec数组，找到递增的序列
        {
            for (int j = 0; j < i; j++)
            {
                if (vec[i] > vec[j])
                {
                    DP[i] = max(DP[i], DP[j] + 1);
                }
            }
            res = max(res, DP[i]); //维护最大值
        }

        cout << res << endl;
    }

    return 0;
}
