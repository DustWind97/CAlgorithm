#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> Calculate(vector<vector<int>> matrix_1, vector<vector<int>> matrix_2)
{
    int x = matrix_1.size();    // x为第一个矩阵的行数
    int y = matrix_2.size();    // y为第一个矩阵的列数
    int z = matrix_2[0].size(); // z为第三个矩阵的列数
    vector<vector<int>> result; //矩阵result存放乘积的结果
    for (int i = 0; i < x; i++)
    {                    //计算矩阵的乘积，并保存在矩阵result中
        vector<int> tmp; //中间变量tmp
        for (int j = 0; j < z; j++)
        {
            int t = 0; //累加器
            for (int k = 0; k < y; k++)
            {
                t += matrix_1[i][k] * matrix_2[k][j]; //第一个矩阵的第i行×第二个矩阵的第j列
            }
            tmp.push_back(t);
        }
        result.push_back(tmp);
    }
    return result; //返回矩阵result
}

int main()
{
    int x, y, z; // x*y y*z
    // cin >> x >> y >> z;
    //  x第一个矩阵的行数
    //  y第一的列数和第二个矩阵的行数
    //  z第二个矩阵的列数
    while (cin >> x >> y >> z)
    {
        vector<vector<int>> matrix1, matrix2; //二维向量

        //矩阵1输入
        for (int i = 0; i < x; i++) //行
        {
            vector<int> vectemp;
            for (int j = 0; j < y; j++) //列
            {
                int temp;
                cin >> temp;
                vectemp.push_back(temp);
            }
            matrix1.push_back(vectemp);
        }
        //矩阵2输入
        for (int i = 0; i < y; i++) //行
        {
            vector<int> vectemp;
            for (int j = 0; j < z; j++) //列
            {
                int temp;
                cin >> temp;
                vectemp.push_back(temp);
            }
            matrix2.push_back(vectemp);
        }

        //打印矩阵
        vector<vector<int>> matrix = Calculate(matrix1, matrix2);
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < z; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}