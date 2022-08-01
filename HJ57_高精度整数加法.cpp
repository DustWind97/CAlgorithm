#include <iostream>
#include <string>
#include <stack>

using namespace std;


/*
思路用栈存储
*/
//返回字符串倒数第n个字符的数字
int Get(string str, int n)
{
    char ch = str[str.length() - n];
    return ch - '0';
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    int str1len = str1.length(), str2len = str2.length();
    int min_len = min(str1len, str2len);
    stack<int> val;

    int carry = (Get(str1, 1) + Get(str2, 1)) / 10;
    int base = (Get(str1, 1) + Get(str2, 1)) % 10;
    val.push(base);
   // cout << base << " | ";
    for (int i = 2; i <= min_len; i++)
    {
        int temp = carry + Get(str1, i) + Get(str2, i);
        carry = temp / 10;
        base = temp % 10;
        val.push(base);
        //cout << base << " | ";
    }
    //加完倒数第min_len位后还有个carry值
    if (str1len > str2len) // str1比str2长，处理str1
    {
        for (int i = min_len+1; i <= str1len; i++)
        {
            int temp = carry + Get(str1, i);
            carry = temp / 10;
            base = temp % 10;
            val.push(base);
            //cout << base << " | ";
        }
        if (carry)
        {
            val.push(carry);
           // cout << carry << " | ";
        }
    }
    else if (str1len < str2len) // str2比str1长,处理str2
    {
        for (int i = min_len+1; i <= str2len; i++)
        {
            int temp = carry + Get(str2, i);
            carry = temp / 10;
            base = temp % 10;
            val.push(base);
            //cout << base << " | ";
        }
        if (carry)
        {
            val.push(carry);
            //cout << carry << " | ";
        }
    }
    else // str1和str2一样长
    {
        if (carry)
        {
            val.push(carry);
            //cout << carry << " | ";
        }
    }

    //最后出栈输出加法结果
    do
    {
        cout << val.top(); //访问栈顶元素
        val.pop();         //访问完后删除栈顶元素
    } while (val.size());

    return 0;
}