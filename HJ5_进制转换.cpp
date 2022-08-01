#include <iostream>
#include <string>

using namespace std;

/*
    包含头文件#include <string>
    stoi(str, 0, 2); //将字符串 str 从 0 位置开始到末尾的 2 进制转换为十进制

    包含头文件#include <stdlib.h>
    atoi：把字符串nptr转换为int。
    atol：把字符串nptr转换为long int。
    atoll：把字符串nptr转换为long long int。
    atoq：atoq() is an obsolete name for atoll()。
*/
int main()
{
    string str;
    while (cin >> str)
    {
        cout << stoi(str, 0, 16) << endl;//十六进制数转换成十进制数
    }
}
