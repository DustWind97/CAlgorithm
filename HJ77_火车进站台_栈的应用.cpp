#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
方法一：全排列+栈
    特点是通过将待检测序列进行全排列，然后检测这是否是一个出栈序列，如果是就打印输出，如果不是则跳过
*/
bool check(vector<int> vec_in, vector<int> vec_check)
{
    stack<int> st; //定义一个栈用来模拟火车进出站（火车站只有一个进出口，只能先进后出【FILO】）
    int j = 0;     //用来获取待检测出栈序列的下标

    for (int i = 0; i < vec_in.size(); i++) //遍历入栈序列
    {
        st.push(vec_in[i]);                             //将第i个入栈元素入栈
        while (!st.empty() && st.top() == vec_check[j]) //当为出栈序列时检测栈出栈，待检测队列出队列
        {
            st.pop(); //出栈
            j++;
        }
    }
    return st.empty(); //栈为空，出栈成功；栈不为空，出栈失败
}

/*
方法二：DFS搜索+栈
    这道题的dfs比较难理解，我认为主要困难的地方在于，进站的时候也要回溯这里，，每次进行dfs之后一定要回到原来的状态。最后用的set来排序。
*/
void dfs(vector<int> &intrain, stack<int> &s, vector<int> output, set<vector<int>> &st, int index)
{
    if (output.size() == intrain.size())
    {
        st.insert(output);
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        if (i == 0 && !s.empty())
        { //这里出栈
            int temp = s.top();
            s.pop();
            output.push_back(temp);
            dfs(intrain, s, output, st, index); // dfs后一定要回到原来的状态，
            //像什么都没发生一样,这里理解就想像dfs已经把你要的序列保存起来了。
            output.pop_back(); //现在回到原来的状态，准备下一个的进栈
            s.push(temp);
        }
        if (i == 1 && (index != intrain.size() - 1))
        { //这里有的题解的index
            //代表即将要加入的列车序号我这里的代表已经加入到栈的序号。所以
            //当index==intrain.size()-1的时候说明最后一个已经入栈。跳过这里
            index++;
            int temp = intrain[index];
            s.push(temp);
            dfs(intrain, s, output, st, index);
            s.pop();
            index--;
        }
    }
    return;
}

int main()
{
    int n; // n个数
    while (cin >> n)
    {
        //输入n个数放在vec(n)当中
        vector<int> vec_in; //入栈序列
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            vec_in.push_back(temp);
        }

        // 1.全排列法
        vector<int> vec_check; //待检测序列
        vec_check = vec_in;
        sort(vec_check.begin(), vec_check.end()); //将vec_check按照字典顺序排序
        do
        {
            if (check(vec_in, vec_check)) //打印合法的出栈顺序
            {
                for (int i = 0; i < n; i++)
                    cout << vec_check[i] << " ";
                cout << endl;
            }
        } while (next_permutation(vec_check.begin(), vec_check.end())); // next_permutation下一个全排列函数，将vec_check进行一次全排列，得到新的待检测序列


        cout << "上方为全排列法--------------------------------------------------下方为DFS搜索回溯法" << endl;

        // 2.DFS搜索法
        set<vector<int>> st; //最后需要字典序
        stack<int> s;        //火车的入栈
        s.push(vec_in[0]);   //默认先把第一辆火车入栈,不然空的是没法输出的。
        int index = 0;       //这里就是默认第一个已经进栈
        vector<int> output;  //每一个序列的输出
        dfs(vec_in, s, output, st, 0);
        for (auto it = st.begin(); it != st.end(); it++)
        {
            for (int i = 0; i < vec_in.size(); i++)
            {
                cout << (*it)[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}