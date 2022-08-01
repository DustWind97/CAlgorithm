#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
方法一：集合思想
    当第一个砝码进来后      {0} 变成 {0,0+1}-->{0,1}
    当第二个砝码进来后      {0，1} 变成 {0，1，0+1，1+1}-->{0,1,2}
    当第三个砝码进来后      {0,1,2} 变成{0，1，2，0+2，1+2，2+2}-->{0,1,2,3,4}
*/
void Set(vector<int> weight, vector<int> num)
{
    unordered_set<int> dict;                //集合用于去重
    dict.insert(0);                         // 0也是一种重量
    for (int i = 0; i < weight.size(); i++) //遍历每一种砝码
    {
        for (int j = 0; j < num[i]; j++) //遍历砝码每一个数量
        {
            unordered_set<int> dict_match(dict); //声明这个的目的是为了每次在原来的已有重量进行配对
            for (auto it = dict_match.begin(); it != dict_match.end(); it++)
            {
                dict.insert(*it + weight[i]);
            }
        }
    }
    cout << dict.size() << endl; //最后集合的大小就是种类
}

/*
方法二：动态规划
    我们可以先计算出所有砝码总重量，然后用长为总重量sum+1的bool型的dp数组计算每种重量是否可能出现，最后遍历这个dp数组统计每种重量出现的次数。
    首先dp[0]=1，然后我们遍历每个砝码（即每种重量的每一个），每次从sum开始往下递减，如果该重量k减去当前遍历到的这个砝码的重量得到的那个重量已经出现了即已经被别的组装好了，那我们就认为这个重量可以出现，置为1.
    这个逻辑和背包问题很像：dp[k]=dp[k−weight[i]]
*/
void Dynamic_Programming(vector<int> weight, vector<int> num)
{
    //首先计算可以出现的最大总重量
    int sum = 0;
    for (int i = 0; i < weight.size(); i++)
    {
        sum += num[i] * weight[i]; //砝码总重量
    }

    vector<bool> dp(sum + 1, false); //记录0到sum是否可行 0-sum总共sum+1个数 {false,false,....,false}总共num+1个元素
    dp[0] = true;//重量为0的情况一定满足
    for (int i = 0; i < weight.size(); i++) //遍历每一种砝码
    {
        for (int j = 0; j < num[i]; j++) //遍历砝码每一个数量
        {
            for (int k = sum; k >= weight[i]; k--) //遍历DP，指定重量满足则置true，否则置false
            {
                if (dp[k - weight[i]] == true)
                {
                    dp[k] = true;
                }
            }
        }
    }
    int type = 0;
    for (int i = 0; i <= sum; i++) //找到为1的就是可以组成的质量，计数
    {
        if (dp[i] == true)
        {
            type++;
        }
    }
    cout << type << endl;
}

int main()
{
    //第一行输入：n --- 砝码的种数(范围[1,10])
    int n;
    while (cin >> n)
    {
        //第二行：m1 m2 m3 ... mn --- 每种砝码的重量(范围[1,2000])
        vector<int> weight;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            cin >> temp;
            weight.push_back(temp);
        }
        //第三行：x1 x2 x3 .... xn --- 每种砝码对应的数量(范围[1,10])
        vector<int> num;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            cin >> temp;
            num.push_back(temp);
        }

        //利用给定的砝码可以称出的不同的重量数
        // Set(weight, num);//采用集合方法
        Dynamic_Programming(weight, num); //采用动态规划

    }

    return 0;
}