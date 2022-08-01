#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<string> SplitStr(string str, char mark)
{
    vector<string> vec;
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != mark) //未到分割点
        {
            temp += str[i];
        }
        else //到分割点
        {
            if (temp == "")//如果为空则跳过本次循环（用来过滤空白指令）
            {
                continue;
            }
            else
            {
                vec.push_back(temp);
                temp.clear();
            }
        }
    }
    // vec.push_back(temp);//最后输入有;号，所以不用追加（）

    return vec;
}

void Calculate(vector<string> vec, int *put) //一次计算
{
    long x = 0, y = 0;
    // cout << x << "|" << y << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        char op_dir = vec[i][0];
        long op_num = 0;
        if (vec[i].length() == 2) //长度为2
        {
            op_num = atol(vec[i].substr(1, 1).c_str());
        }
        else if (vec[i].length()== 3) //长度为3
        {
            op_num = atol(vec[i].substr(1, 2).c_str());
        }
    //cout << op_dir << "|" << op_num << endl;

        if (op_dir == 'W') // W 向上
        {
            y = y + op_num;
        }
        else if (op_dir == 'S') // S 向下
        {
            y = y - op_num;
        }
        else if (op_dir == 'A') // A 向左
        {
            x = x - op_num;
        }
        else if(op_dir == 'D')// D 向右
        {
            x = x + op_num;
        }
        //cout << x << "|" << y << endl;
    }
    // cout << x << "|" << y << endl;
    put[0] = x;
    put[1] = y;
}
int main()
{
    string str;
    cin >> str;
    vector<string> vec = SplitStr(str, ';');
    vector<string> legal_input;
    for (int i = 0; i < vec.size(); i++) //遍历vec保留合法的输入
    {
        if ((vec[i][0] == 'W' || vec[i][0] == 'S' || vec[i][0] == 'A' || vec[i][0] == 'D') &&
            ((vec[i][1] >= '0' && vec[i][1] <= '9' && vec[i].length() == 2) ||
             (vec[i][1] >= '0' && vec[i][1] <= '9' && vec[i][2] >= '0' && vec[i][2] <= '9' && vec[i].length() == 3))) //一个合法输入
        {
            legal_input.push_back(vec[i]);
        }
    }

    // for (int i = 0; i < legal_input.size(); i++) //遍历vec保留合法的输入
    // {
    //     cout << legal_input[i] << endl;
    // }

    int put[2] = {0, 0};
    Calculate(legal_input, put);

    cout << put[0] << "," << put[1] << endl;

    return 0;
}