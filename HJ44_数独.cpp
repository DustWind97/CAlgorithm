#include <bits/stdc++.h>
using namespace std;
const int N = 9;
int mp[N][N]; //存储数独

bool find_answer_ok;

bool check(int row, int col, int val)
{ 
    //检验在当前位置填入val后，满足要求与否
    //同行判定
    for (int i = 0; i < 9; i++)
    {
        if (mp[row][i] == val)
        {
            return false;
        }
    }

    //同列判定
    for (int i = 0; i < 9; i++)
    {
        if (mp[i][col] == val)
        {
            return false;
        }
    }

    //同一个九宫格判定
    int limit_row = row / 3 * 3 + 3; //九宫格行的终点
    int limit_col = col / 3 * 3 + 3; //九宫格列的终点
    for (int i = limit_row - 3; i < limit_row; i++)
    {
        for (int j = limit_col - 3; j < limit_col; j++)
        {
            if (mp[i][j] == val)
            {
                return false;
            }
        }
    }
    return true; //同行，同列，同一九宫格均满足返回真
}

void dfs(int row, int col) //搜索坐标
{
    //当前行、列
    if (col == 9) //搜索的方向：从左到右，从上到下----
    {
        row++;
        col = 0;
    }
    if (row == 9 && col == 0)//退出条件，查找完成退出递归
    {
        find_answer_ok = true;
        return;
    }


    if (mp[row][col] == 0)//找到需要补充的值
    {
        for (int i = 1; i <= 9; i++)
        {
            if (check(row, col, i))
            { 
                // check后满足
                mp[row][col] = i;//正确后补充数值
                dfs(row, col + 1);
                if (find_answer_ok)
                { 
                    //已经找到答案了，直接return
                    return;
                }
                mp[row][col] = 0; //没找到答案，回溯
            }
        }
    }
    else//没有找到需要补充的值，则继续查找
    {
        dfs(row, col + 1);
    }
}
int main()
{
    //输入
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> mp[i][j];
        }
    }

    //进行dfs搜索到0的地方并填上
    dfs(0, 0); //起点坐标（0，0）

    //输出
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
