#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
/*
方法一：递归思想DFS搜索树
放苹果分为两种情况，一种是有盘子为空，一种是每个盘子上都有苹果。
令(m,n)表示将m个苹果放入n个盘子中的摆放方法总数。
1.假设有一个盘子为空，则(m,n)问题转化为将m个苹果放在n-1个盘子上，即求得(m,n-1)即可
2.假设所有盘子都装有苹果，则每个盘子上至少有一个苹果，即最多剩下m-n个苹果，问题转化为将m-n个苹果放到n个盘子上
即求(m-n，n)
*/
int DFS(int m, int n)
{
    if (m < 0 || n < 0) //第一种中止条件，退出递归
        return 0;
    else if (m == 1 || n == 1) //第二种中止条件，退出递归
        return 1;
    else
        return DFS(m, n - 1) + DFS(m - n, n);
}

/*
方法二：二维动态规划(动态规划本质上就是递归算法加上记忆功能)
初始状态转移矩阵dp[n][m]
dp[i][j]就是我们现在有i个盘子，但是我们要放进去j个苹果的方法数是dp[i][j]    dp指的是方法数
    如果我们的盘子数量大于我们的苹果数量 i>j，那么我们的dp[i][j]=dp[i][i]
    如果我们的苹果数量大于我们的盘子数量 j>=i, 那么我们的dp[i][j]=dp[i−j][j]+dp[i][j−1]

状态转移方程为：dp[i][j]=dp[i-1][j] + (j-i<0?0:dp[i][j-i])
*/
int Dynamic_Programing(int m, int n)
{
    if (!(m >= 0 && m <= 10)) // m数据输入不符合要求
        return -1;
    if (!(n >= 1 && n <= 10)) // n数据输入不符合要求
        return -1;
    if (1 == n) //只有一个盘子，分法唯一
        return 1;
    if (m <= 1)
        return 1;
    if (m <= n)
        n = m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); //初始化二维向量，全部位置均置0（表示没有此种分法）
    dp[1] = vector<int>(m + 1, 1);
    for (int i = 1; i <= n; ++i)
        dp[i][0] = dp[i][1] = 1;

    for (int i = 2; i <= n; ++i) //遍历n元素
    {
        for (int j = 2; j <= m; ++j) //遍历m元素
        {
            /*
            //i个苹果放j个盘子
            //拿出第j个盘子，第j个盘子可以放，可以不放
            //①如果第j个盘子放苹果，因为盘子都是一样的,所以相当于所有盘子都放苹果,那么相当于求i-j个苹果放j个盘子
            //②如果第j个盘子不放苹果,相当于求i个苹果放j-1个盘子
            */
            // dp[i][j] = dp[i - 1][j] + (j - i < 0 ? 0 : dp[i][j - i]);
            //  cout << i << ":" << j << " " << dp[i][j] << endl;

            //另外一种方法
            if (i > j)
            {
                dp[i][j] = dp[i][i];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - i];
                /*
                i个盘子放j个苹果，可以分成两部分，
                    如果第i个盘子不放苹果，那么就是其他i-1个盘子放j个苹果      dp[i-1][j]
                    *如果第i个盘子放苹果，相当于i个盘子都可以放苹果，那么就等价于所有i个盘子可以放j-i个苹果       dp[i][j - i]
                */
            }
        }
    }

    return dp[n][m];
}

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        //将m个苹果放入到n个盘子当中，问有多少种分法
        // cout << DFS(m, n) << endl;
        cout << Dynamic_Programing(m, n) << endl;
    }

    return 0;
}