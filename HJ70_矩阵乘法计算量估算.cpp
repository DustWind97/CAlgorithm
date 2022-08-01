#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; //矩阵的个数n
    while (cin >> n)
    {
        vector<pair<int, int>> matrix; //存放每个矩阵的行数和列数
        for (int i = 0; i < n; i++)
        { //依次输入n个矩阵的行数和列数，并保存在容器matrix中
            int row, arrange;
            cin >> row >> arrange;
            matrix.push_back(make_pair(row, arrange)); //绑定matrix
        }
        string rule;                        //存放计算的法则也就是计算的式子
        cin >> rule;                        //输入法则rule
        stack<char> sign;                   //符号栈
        stack<pair<int, int>> Stack_matrix; //矩阵栈
        int sum = 0;                        //乘法次数
        int num_matrix = 0;               //遍历计算规则时的第多少个字符
        for (int i = 0; i < rule.length(); i++)
        { //按照计算法则求矩阵的乘法次数
            if (rule[i] == '(')
            {
                //'('为待匹配的符号，压入符号栈中
                sign.push(rule[i]);
            }
            else if (rule[i] >= 'A' && rule[i] <= 'Z')
            {
                //如果为字母，将该字母对应的矩阵添加到矩阵栈中
                //Stack_matrix.push(matrix[rule[i] - 'A']);//---------矩阵是按照ABCD的顺序默认排下去的
                Stack_matrix.push(matrix[num_matrix]);
                num_matrix++;
            }
            else if (rule[i] == ')')
            {
                //如果当前符号为')'，将符号栈中的'('出栈
                sign.pop();//顶部的出栈
                pair<int, int> matrix2 = Stack_matrix.top(); //依次弹出矩阵栈的相邻两个栈顶矩阵
                Stack_matrix.pop();
                pair<int, int> matrix1 = Stack_matrix.top();
                Stack_matrix.pop();
                sum += matrix1.first * matrix1.second * matrix2.second;      //累加乘法次数
                Stack_matrix.push(make_pair(matrix1.first, matrix2.second)); //将矩阵相乘后得到的新矩阵的构造重新入栈
            }
        }
        cout << sum << endl; //输出矩阵相乘的乘法总次数
    }
    return 0;
}
