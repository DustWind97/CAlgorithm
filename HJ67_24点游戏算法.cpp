#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*************************************************************************************************************************/
/*
方法一：暴力穷举
*/
double cal(double a, double b, char c)
{ //根据运算符运算结果
    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

bool check(vector<double> &nums)
{
    char op[4] = {'+', '-', '*', '/'};
    sort(nums.begin(), nums.end()); //先按照从小到大排
    do
    {
        for (int i = 0; i < 4; i++) //遍历三个位置的所有可能运算符
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                {
                    double first = cal(nums[0], nums[1], op[i]); //依次运算
                    double second = cal(first, nums[2], op[j]);
                    if (cal(second, nums[3], op[k]) == 24) //判断是否等于24
                        return true;
                }
    } while (next_permutation(nums.begin(), nums.end())); //依次找到其他排列
    return false;
}

/*************************************************************************************************************************/
/*
方法二：
    DFS采用递归搜索的方法
*/
bool check(vector<double> nums, double result)
{                     //递归检查能否组成24
    if (nums.empty()) //数组为空，判断等不等于24
        return result == 24;
    for (int i = 0; i < nums.size(); i++)
    { //遍历剩下的数字
        vector<double> rest(nums);
        rest.erase(rest.begin() + i);     //删去使用的数字
        if (check(rest, result + nums[i]) //分别 进行加减乘除4种运算
            || check(rest, result - nums[i]) || check(rest, result * nums[i]) || check(rest, result / nums[i]))
            return true;
    }
    return false;
}
/*************************************************************************************************************************/

int main()
{
    vector<double> vec;
    for (int i = 0; i < 4; i++)
    {
        double temp = 0;
        cin >> temp;
        vec.push_back(temp);
        // cout << temp << " ";
    }

    //对vec进行处理
    if (check(vec, 24))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}