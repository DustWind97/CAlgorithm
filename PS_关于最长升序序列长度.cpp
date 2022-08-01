#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*****************************************************************************************************************************/
/*
方法一：递归
*/
int Recursion(vector<int> &vec, int i) //第i个元素
{
    if (i == vec.size() - 1) //递归调用的结束标志
    {
        return 1; //搜寻到最后一个都未找到比第i个元素大的元素返回最大长度为1
    }

    int maxlen = 1;                          //默认最短长度为1（只含元素本身的序列）
    for (int j = i + 1; j < vec.size(); j++) //每一次外循环一次就维护一次大于第i个元素的升序序列
    {
        if (vec[j] > vec[i])
        {
            //维护最大升序序列长度
            maxlen = max(maxlen, Recursion(vec, j) + 1); //找到比第i个元素大的元素则递归调用
        }
    }
    return maxlen;
}

/*****************************************************************************************************************************/
/*
方法二：迭代
*/
void Iterate(vector<int> vec)
{
}

/*****************************************************************************************************************************/
/*
方法三：动态规划    最优子结构，无后效性
*/
int DynamicProcessing(vector<int> &vec)
{
    //定义一个n长度的DP辅助数组,初始赋值均为1-----------DP[i]表示，到第 i 号元素为止，最长上升子序列的长度
    vector<int> DP(vec.size(), 1); //每个元素构成的升序序列最小长度就应当为1
    int maxlen = 1;
    for (int i = 0; i < vec.size(); i++) //遍历vec数组，找到递增的序列
    {
        for (int j = 0; j < i; j++) //每一次外循环一次就维护一次小于前（i-1）个元素的升序序列
        {
            if (vec[i] > vec[j])
            {
                DP[i] = max(DP[i], DP[j] + 1); //状态转移方程

                /*状态方程另解*/
                // DP[i] = DP[j] + 1;
                // maxlen = maxlen > DP[i] ? maxlen : DP[i]; //找到最大长度
            }
        }
        maxlen = max(maxlen, DP[i]); //维护最大升序序列长度
    }

    return maxlen;
}

/*****************************************************************************************************************************/
/*
方法四：动态规划改进---二分法动态规划
*/
int biSearch(int x, vector<int> &dp) //二分查找
{                                    //二分查找函数
    int left = 0, right = dp.size(), mid;
    while (left <= right)
    {
        mid = (right + left) / 2;
        if (dp[mid] >= x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}
int DynamicProcessing_BinSearch(vector<int> &arr) //动态规划
{
    vector<int> len; //设置数组长度大小的动态规划辅助数组
    vector<int> dp;  //用于二分划分的辅助数组
    dp.push_back(arr[0]);
    len.push_back(1);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > dp[dp.size() - 1])
        {
            dp.push_back(arr[i]);
            len.push_back(dp.size());
        }
        else
        {
            int t = biSearch(arr[i], dp); //二分查找，找到第一个大于arr[i]的dp位置
            dp[t] = arr[i];
            len.push_back(t + 1);
        }
    }
    return dp.size();
}
/*****************************************************************************************************************************/

int main()
{
    int n;
    while (cin >> n)
    {
        //获取一个规格为n的序列
        vector<int> vec;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }

        //采用递归
        int maxlen = 1;
        for (int i = 0; i < vec.size(); i++) //从第0个元素开始递归,统计以第i个元素为根节点的树的深度
        {
            maxlen = max(maxlen, Recursion(vec, i));
        }
        cout << "采用递归的结果：" << maxlen << endl;

        //采用迭代
        // cout << "采用迭代的结果：" << Iterate(vec) << endl;

        //采用动态规划
        cout << "采用动态规划的结果：" << DynamicProcessing(vec) << endl;

        //采用二分查找动态规划
        cout << "采用二分查找动态规划的结果：" << DynamicProcessing_BinSearch(vec) << endl;
    }
    return 0;
}