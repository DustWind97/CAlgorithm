// #include <iostream>
// #include <string>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {

//     return 0;
// }

#include <iostream>
#include <string>
#include <stack>

using namespace std;
/*
解题思路：双栈法
具体做法：

上述的子问题也用栈来解决括号，我们用一个栈记录刚刚的计算结果，每次都与栈顶元素计算，然后加入栈顶，用另一个栈记录包括括号在内的所有运算符，根据运算优先级来计算第一个栈中的内容。
因为不用考虑括号的合法性，我们可以只在栈中添加小括号。遍历的时候遇到左括号就将其加入栈中，遇到右括号依次弹出运算符栈和数字栈中的内容进行计算，直到遇到左括号为止，就相当于计算了一个子问题，运算结果依旧存在栈中，不影响后续的计算。

遇到数字要区分正负号和加减号，可以用一个flag标记每轮是否出现过了数字了，数字之前的为正负号，数字之后的为加减号。
*/

//第一，计算式
void compute(stack<int> &st1, stack<char> &st2)
{
    //根据栈顶运算符弹出栈顶两个元素进行运算
    int b = st1.top();
    st1.pop();
    int a = st1.top();
    st1.pop();
    char op = st2.top(); //栈顶运算符
    st2.pop();
    if (op == '+')
        a = a + b; //加
    else if (op == '-')
        a = a - b; //减
    else if (op == '*')
        a = a * b; //乘
    else if (op == '/')
        a = a / b; //除
    st1.push(a);
}

//第二，优先级的确定
bool priority(char m, char n)
{                 //比较运算符优先级
    if (m == '(') //括号优先级最高
        return false;
    else if ((m == '+' || m == '-') && (n == '*' || n == '/')) //加减法小于乘除法
        return false;
    return true;
}

int main()
{
    // 3+2*{1+2*[-4/(8-6)+7]}的四则运算
    string s;
    while (cin >> s)
    {
        stack<int> st1;  //记录运算数字
        stack<char> st2; //记录运算符
        st2.push('(');   //整个运算式添加括号
        s += ')';
        bool flag = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') //如果是左括号都在运算符栈加入(
                st2.push('(');
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            { //遇到右括号
                while (st2.top() != '(')
                { //弹出开始计算直到遇到左括号
                    compute(st1, st2);
                }
                st2.pop(); //弹出左括号
            }
            else if (flag)
            { //运算符
                while (priority(st2.top(), s[i]))
                {                      //比较运算优先级
                    compute(st1, st2); //可以直接计算
                }
                st2.push(s[i]); //需要将现阶段加入栈中等待运算
                flag = false;
            }
            else
            {                                   //数字
                int j = i;                      //记录起始
                if (s[j] == '-' || s[j] == '+') //正负号
                    i++;
                while (isdigit(s[i]))
                {
                    i++;
                }
                string temp = s.substr(j, i - j);
                st1.push(stoi(temp)); //截取数字部分，转数字
                i--;
                flag = true; //数字结束，下一次flag为true就是运算符了
            }
        }
        cout << st1.top() << endl; //输出
    }

    return 0;
}
