#include <iostream>
#include <string>

using namespace std;

//思路：接收一个字符串，然后反向查找第一个空格
int main()
{
    string str;
    //理解getline函数的使用
    //死循环，此程序可以无限重复
    while (getline(cin, str))
    { //通过cin方式键入一个一个str字符串并将该str长度循环
        int x = 0, len = str.size();
        for (int i = len - 1; i >= 0; --i)
        {
            if (str[i] == ' ')
            {
                x = i + 1;
                break;
            }
        }
        cout << "最后一个单词长度为：" << (len - x) << endl;
    }
    return 0;
}