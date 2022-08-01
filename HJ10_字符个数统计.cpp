#include <iostream>
#include <set>

using namespace std;

int main()
{
    string str;        //存放输入的字符串
    getline(cin, str); //获取输入的一行字符串
    set<char> ch;      //使用set容器
    for (int i = 0; i < str.length(); i++)
    {
        ch.insert(str[i]); //将text中的字符逐个添加到set容器中
    }
    cout << ch.size() << endl; //输出set容器的长度，即为不同字符的个数
}