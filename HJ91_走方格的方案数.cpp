#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        /*只能往右和往下走，不能往左和往上走*/
        //初始化
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // dp[i][j]表示到第i行j列为止的方案数

        for (int i = 0; i < dp.size(); i++) //行
        {
            for (int j = 0; j < dp[0].size(); j++) //列
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 && j == 0) //最开始，一种方法
                    dp[i][j] = 1;
                else if (i == 0) //行数到顶，等于旁边列的方法
                    dp[i][j] = dp[i][j - 1];
                else if (j == 0) //列数到左边，等于旁边行的方法
                    dp[i][j] = dp[i - 1][j];
                else //等于左边加上边的方法
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        cout << dp[n][m] << endl;
    }

    return 0;
}