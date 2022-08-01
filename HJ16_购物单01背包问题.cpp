// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// using namespace std;

// int main()
// {
//     int N, m;
//     cin >> N >> m;
//     // 由于价格是10的整数倍，处理一下以降低空间/时间复杂度
//     // N = 10;
//     // 商品总数量小于60
//     vector<vector<int>> prices(60, vector<int>(3, 0));                // 价格
//     vector<vector<int>> priceMultiplyPriority(60, vector<int>(3, 0)); // 重要程度
//     for (int i = 1; i <= m; ++i)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         // a =a/10;
//         b *= a;
//         if (c == 0)
//         {
//             prices[i][0] = a;
//             priceMultiplyPriority[i][0] = b;
//         }
//         else
//         {
//             if (prices[c][1] == 0)
//             { //表示输入了第一个附件
//                 prices[c][1] = a;
//                 priceMultiplyPriority[c][1] = b;
//             }
//             else
//             { //表示输入了第二个附件，附件最多为2
//                 prices[c][2] = a;
//                 priceMultiplyPriority[c][2] = b;
//             }
//         }
//     }
//     // 使用分组背包
//     vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));
//     for (int i = 1; i <= m; ++i)
//     {
//         for (int j = 1; j <= N; ++j)
//         {
//             // a是价格也就是主件占用的空间
//             int a = prices[i][0], b = priceMultiplyPriority[i][0];
//             // c是价格，也就是附件1占用的空间
//             int c = prices[i][1], d = priceMultiplyPriority[i][1];
//             // e是价格，也就是附件2占用的空间
//             int e = prices[i][2], f = priceMultiplyPriority[i][2];
//             //状态转移方程
//             // j >= a不成立，则第i个不放入价值为dp[i - 1][j]
//             // j >= a成立，则放入第i个物品，并且该物品是主件，dp[i - 1][j - a]前i-1个物品价值，空间为j - a
//             //这句话可以改写成容易理解的0-1背包问题
//             /*
//                 dp[i][j]=dp[i - 1][j];
//                 if(j>=a)
//                 {
//                     dp[i][j]=max(dp[i-1][j-a]+b,d[i][j]);
//                 }
//             */
//             dp[i][j] = j >= a ? max(dp[i - 1][j - a] + b, dp[i - 1][j]) : dp[i - 1][j];
//             //判断是否放入附件1
//             dp[i][j] = j >= (a + c) ? max(dp[i - 1][j - a - c] + b + d, dp[i][j]) : dp[i][j];
//             //判断是否放入附件2
//             dp[i][j] = j >= (a + e) ? max(dp[i - 1][j - a - e] + b + f, dp[i][j]) : dp[i][j];
//             //判断是否放入附件1、2
//             dp[i][j] = j >= (a + c + e) ? max(dp[i - 1][j - a - c - e] + b + d + f, dp[i][j]) : dp[i][j];
//         }
//     }
//     cout << dp[m][N] << endl;
// }



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
动态规划：
思路：总钱数N是10的倍数，除以10减少范围，且价格v除以10；根据附件标签q将主件、附件分别存储价格、总值。
*/
 
int main()
{
    int N, m; // N 表示总钱数， m希望购买物品的个数
    cin>>N>>m;
    N /= 10; // 每件物品的价格都是10的整数倍，因此这里除以10，减少取值范围，结束时需要乘以10以还原。
    vector<vector<int>> price(m+1, vector<int>(3, 0)); // 主键、附件价格
    vector<vector<int>> sumValue(m+1, vector<int>(3, 0)); // 价格*重要度
    vector<vector<int>> dp(m+1, vector<int>(N+1, 0));  //dp数组
    for (int i = 1; i <= m; i++) {
        int v, p, q; // v 表价格, p表示重要度， q表示主件还是附件（0表示主件，大于表示附件编号）
        cin>>v>>p>>q;
        v /= 10; // 所有价格都是10倍
        p *= v; // 总值= 重要度*价格
        if (q == 0) { // 主件
            price[i][0] = v; //主件价格
            sumValue[i][0] = p; //主件总值
        } else if (q > 0) { // 附件
            if (price[q][1] == 0) { //第一个附件
                 price[q][1] = v; //第一个附件价格
                 sumValue[q][1] = p; //第一个附件总值
            } else {
                 price[q][2] = v; //第二个附件价格
                 sumValue[q][2] = p; //第二个附件总值
            }
        }
    }
   
    // 根据动态规划原则，求最大值通过分阶段决策，即分阶段求最大值，将所有阶段的最大值相加等于总值。
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= N; j++) {
            // 必须足够的钱购买主件
            // 主件最大总值
            if (j >= price[i][0]) { //主件
                //dp[i-1][j-price[i][0]] + sumValue[i][0] 表示当前的总值，dp[i-1][j]表示上一次的总值
                dp[i][j] = max(dp[i - 1][j - price[i][0]] + sumValue[i][0], dp[i-1][j]); // 当前总值与上一次总值比较，取最大值
            } else {
                 dp[i][j] =  dp[i - 1][j]; // 上一次总值
            }
            
              //可以买主件 + 第一个附件
            if (j >= price[i][0] + price[i][1]) { 
                dp[i][j] = max(dp[i - 1][j - price[i][0] - price[i][1]]  + sumValue[i][0] +  sumValue[i][1],  dp[i][j]);
            }
            //可以买主件 + 第二个附件
            if (j >= price[i][0] + price[i][2]) { 
                dp[i][j] = max(dp[i - 1][j - price[i][0] - price[i][2]]  + sumValue[i][0] + sumValue[i][2],  dp[i][j]);
            }
             //可以买主件 + 两个附件
            if (j >= price[i][0] + price[i][1] + price[i][2]) { 
                 dp[i][j] = max(dp[i - 1][j - price[i][0] - price[i][1] - price[i][2]]  + sumValue[i][0] + sumValue[i][1] + sumValue[i][2],  dp[i][j]);
            } 
        }
    }
    cout << dp[m][N] * 10 << endl;  //输出要乘回10倍
    return 0;
}
