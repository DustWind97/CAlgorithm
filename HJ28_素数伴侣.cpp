#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//判断是否是素数
bool isPrime(int num)
{
    if (num <= 1) // 0和1不是素数
    {
        return false;
    }
    else if (num == 2 || num == 3) // 2和3是素数
    {
        return true;
    }
    else
    {
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0) //判定是否有余数
            {
                return false;
            }
        }
    }
    return true; //遍历之后若没找到因数就返回为素数
}

//查找满足条件的匹配
bool find(int oddi, vector<int> &vec_even, vector<bool> &flag, vector<int> &match)
{
    for (int i = 0; i < vec_even.size(); i++) //遍历偶数组
    {
        if (isPrime(oddi + vec_even[i])) //两数相加为素数
        {
            if (flag[i] == false) //之前遍历还未用到过
            {
                flag[i] = true;                                             //将其置为已使用
                if (match[i] == 0 || find(match[i], vec_even, flag, match)) //如果第i个偶数还未配对，或者跟它配对的奇数还有别的选择
                {
                    match[i] = oddi; //则配对该数
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    // int q;
    // while (cin >> q)
    // {
    //     if (isPrime(q) == 1)
    //     {
    //         cout << q << "是素数" << endl;
    //     }
    //     else
    //     {
    //         cout << q << "不是素数" << endl;
    //     }
    // }

    int n;
    while (cin >> n)
    {
        vector<int> vec; //输入集合
        //只有一个奇数一个偶数才能构成
        vector<int> vec_odd;  //奇数组
        vector<int> vec_even; //偶数组
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp % 2 == 0) //偶数
            {
                vec_even.push_back(temp);
            }
            else if (temp % 2 == 1) //奇数
            {
                vec_odd.push_back(temp);
            }
            vec.push_back(temp);
        }

        if (vec_odd.size() == 0 || vec_even.size() == 0) //奇数组或者偶数组为空，则无法找到配对
        {
            cout << 0 << endl;
        }
        else
        {
            int counter = 0;                         //用来统计可以匹配的组数
            vector<int> match(vec_even.size(), 0);   //偶数组匹配的奇数组（回溯使用）---偶数组的每个偶数也要匹配奇数组的
            for (int i = 0; i < vec_odd.size(); i++) //遍历奇数组
            {
                vector<bool> flag(vec_even.size(), false);   //表示一次遍历中是否用到该数，如果用到则跳过
                if (find(vec_odd[i], vec_even, flag, match)) //找到则累加
                {
                    counter++;
                    // cout << vec_odd[i] << endl;
                }
            }
            cout << counter << endl;
        }
    }

    return 0;
}