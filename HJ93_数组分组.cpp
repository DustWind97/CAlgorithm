#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
解决方法一：递归
解题思路
（ 1 ） 将输入的数字放进列表nums
（ 2 ） 提取其中的5 的倍数到s-5 ， 除了5 的倍数外的3 的倍数到s-3 ， 其余的到s-other
（ 3 ） 将nums 的总和除以2定义为average， s-5 的总和为target
（ 4 ） 问题转化为用target 加上s-other 中的任意个数等于average
（ 5 ） 用递归解决该问题， 设归函数为 find
*/
void Recursion()
{
}
/*
解决方法二：动态规划
*/
bool DynamicProcessing(int sum5, int sum3, int nor35, vector<int> &v)
{

    int diff = abs(sum5 - sum3);
    if (nor35 == 0 && (diff == 0))
        return true;      //这里的逻辑好理解差值为0，且没有第三组
    int x = nor35 + diff; //这里求和想看看它们能否被评分因为整个集合都是整数，如果是
    //奇数除以2是小数，不可能又和可以组成，只有能平分成整数在考虑有没有数可以组合。
    if (diff == 0 && (v.size() == 0))
        return true;

    if (x % 2 != 0)
        return false;
    else
    {
        x /= 2;
        vector<vector<int>> dp(v.size(), vector<int>(x + 1, 0));
        for (int i = 0; i < v.size(); i++)
        {
            dp[i][0] = 1;
        }

        dp[0][v[0]] = 1;

        for (int i = 1; i < v.size(); i++)
        {
            for (int j = 1; j < x + 1; j++)
            {
                if (j >= v[i])
                    dp[i][j] = dp[i - 1][j - v[i]] || dp[i - 1][j]; //这里i-1代表
                //没有v[i]的时候的和也可以组成j
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[v.size() - 1][x];
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        //构建数据集
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }

        //处理分组
        vector<int> vec_3;
        vector<int> vec_5;
        vector<int> vec_nor;
        int sum_3 = 0;    //所有3的倍数之和（不包括5的倍数）
        int sum_5 = 0;    //所有5的倍数之和
        int sum_rest = 0; //剩余所有之和
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] % 3 == 0 && vec[i] % 5 != 0) //所有3的倍数（不包括5的倍数）
            {
                vec_3.push_back(vec[i]);
                sum_3 += vec[i];
            }
            if (vec[i] % 5 == 0) //所有5的倍数
            {
                vec_5.push_back(vec[i]);
                sum_5 += vec[i];
            }
            if (vec[i] % 3 != 0 && vec[i] % 5 != 0) //既不是3的倍数，也不是5的倍数
            {
                vec_nor.push_back(abs(vec[i])); //加绝对值对最后判断能不能分成两个和相等时没有影响
                sum_rest += abs(vec[i]);
            }
        }

        //对vec_nor进行处理，看是否能满足要求----采用动态规划
        // vec_nor要么加入sum_3当中，要么加入sum_5当中
        bool canpatiton = false;
        canpatiton = DynamicProcessing(sum_5, sum_3, sum_rest, vec_nor);
        cout << boolalpha << canpatiton << endl;
    }

    return 0;
}