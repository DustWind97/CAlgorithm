#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool isSingQueue(vector<int> vec)
{
    int max_num = vec[0]; //最大值
    int max_index = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] > max_num)
        {
            max_num = vec[i];
            max_index = i;
        }
    }

    //将vec以i为分界线分割为两个vec，一个判断升序，一个判断降序
    for (int i = 0; i <= i - 1; i++)
    {
        if (vec[i] >= vec[i + 1]) //在i的左侧找到降序的，直接返回false
        {
            return false;
        }
    }
    for (int i = i; i < vec.size() - 1; i++)
    {
        if (vec[i] <= vec[i + 1]) //在i的右侧找到升序的，直接返回false
        {
            return false;
        }
    }
    return false; //遍历完都没有false则为成功
}

int main()
{
    int N;
    while (cin >> N)
    {
        vector<int> vec;
        for (int i = 0; i < N; i++)
        {
            int temp = 0;
            cin >> temp;
            vec.push_back(temp);
        }

        //对vec进行处理
        vector<int> DP_left2right(N, 1);
        vector<int> DP_right2left(N, 1);

        // 正序遍历
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (vec[i] > vec[j])
                {
                    DP_left2right[i] = max(DP_left2right[i], DP_left2right[j] + 1);
                }
            }
        }
        // 逆序遍历
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = N - 1; j > i; j--)
            {
                if (vec[i] > vec[j])
                {
                    DP_right2left[i] = max(DP_right2left[i], DP_right2left[j] + 1);
                }
            }
        }
        // 求和得到最长先增后减子序列的长度
        int maxNum = 0;
        for (int i = 0; i < N; i++)
        {
            if (DP_left2right[i] + DP_right2left[i] - 1 > maxNum)
                maxNum = DP_left2right[i] + DP_right2left[i] - 1;
        }
        // 输出
        cout << N - maxNum << endl;
    }

    return 0;
}