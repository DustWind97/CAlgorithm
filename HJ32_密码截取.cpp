#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/**************************************************************************************************************************************/
/*
方法一：动态规划
    时间复杂度：o(n^2)
    空间复杂度：o(n^2)---原因是引入辅助数组增加了空间开销
*/
void DynamicProcessing(string str)
{
    int len = str.length();
    vector<vector<bool>> dp(len, vector<bool>(len, false)); // dp[j][i]=1表示从j到i是回文子串
    int maxlen = 1;                                         //初始为1
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j) //奇数长度子串
            {
                dp[j][i] = true;
            }
            else if (i - j == 1) //偶数长度子串
            {
                dp[j][i] = (str[i] == str[j]);
            } //相等赋值为true，不相等赋值为false
            else
            {
                dp[j][i] = (str[i] == str[j] && dp[j + 1][i - 1]);
            } //这两个字符相等，同时中间缩也要相等


            if (dp[j][i] && i - j + 1 > maxlen) //维护最大值
            {
                maxlen = i - j + 1;//例如，3-5总共有(5-3+1)个数
            }
        }
    }
    cout << maxlen << endl;
}

/**************************************************************************************************************************************/
/*
方法二：中心扩展法
    时间复杂度：o(n^2)
    空间复杂度：o(1)
*/
//从字符串中间获取子字符串
int get_substr(string str, int left, int right) //第一个参数为待处理字符串，第二个参数为子字符串的左边部分，第三个参数为子字符串的右边部分
{
    int len = 0;
    //遍历待处理字符串
    while (left >= 0 && right <= str.size() - 1 && str[left] == str[right])
    {
        left--;
        right++;
        len = right - left - 1; // len为维护最大长度
    }
    return len;
}

void CentralExpand(string str)
{
    while (str.length() == 0)
    {
        cout << 0 << endl;
        return;
    }

    while (str.length() == 1)
    {
        cout << 1 << endl;
        return;
    }

    int maxlen = 0;
    for (int i = 0; i < str.length() - 1; i++)//遍历整个字符串
    {
        int m1 = get_substr(str, i, i);     //子字符串长度为奇数（中间有一个字符）
        int m2 = get_substr(str, i, i + 1); //子字符串长度为偶数（中间有两个字符）
        maxlen = max(maxlen, max(m1, m2));  //维护最大值
    }
    cout << maxlen << endl;
}
/**************************************************************************************************************************************/

int main()
{
    string str;
    while (cin >> str)
    {
        //采用动态规划
        DynamicProcessing(str);
        //采用中心扩展法
        CentralExpand(str);
    }

    return 0;
}