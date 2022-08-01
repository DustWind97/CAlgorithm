#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

//分割字符串1-----无法按照空格分割
vector<string> Split_Without_Space(string str, char mark) //待分割标志（注意是以字符的形式输入分割标志）
{
    string temp;
    temp.clear();
    vector<string> vec;

    str += mark; //在末尾加个空格方便查找并分段处理
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != mark)
        {
            temp += str[i];
            // cout <<str[i]<<" "<<temp<<endl;
        }
        else
        {
            // cout <<temp <<endl;
            vec.push_back(temp);
            temp.clear();
        }
    }
    return vec;
}

//分割字符串-----可以按照空格分割
vector<string> Split(string str, char *mark) //-----待分割的标志（注意要以字符串的形式输入分割标志）
{
    //方法一: strtok
    char *s = new char[str.size() + 1];
    strcpy(s, str.c_str());
    char *p = strtok(s, mark);
    vector<string> words;
    while (p)
    {
        words.push_back(p);
        p = strtok(NULL, mark);
    }
    return words;
}

int main()
{
    /*
    思路：给定一个vector<string>来存放字符串片段，遍历整个字符串，如果遇到空格就将这之间的一段放入vector中，如果遇到双引，则将此双引号中间的内容放入vector中
    对于xcopy /s c:\\ d:\\e
    参数1：命令字xcopy
    参数2：字符串/s
    参数3：字符串c:\\
    参数4: 字符串d:\\e
    */
    string input;
    while (getline(cin, input)) //注意如果以cin获取字符串的话会屏蔽掉空格
    {
        int len = input.length();
        int count = 0;
        vector<string> vec;
        string temp = "";
        for (int i = 0; i < len; i++)
        {
            if (input[i] == '"' && (i != len - 1)) //找到双引号，并且还没结束
            {
                int j = i + 1;
                while ((j < len) && input[j] != '"') //找到前后两个双引号的位置
                {
                    j++;
                }
                count++;
                vec.push_back(input.substr(i + 1, j - i - 1));
                i = j;//处理这一段之后就把j赋给i，下一次循环从i开始
            }
            else if (input[i] == ' ' || (i == len - 1)) //遇到空格或者结束？？？？？？？？
            {
                if (i == len - 1)
                    temp += input[i];
                if (temp != "")
                {
                    vec.push_back(temp);
                    count++;
                }
                temp = "";
            }
            else
                temp += input[i];//input[i]没遇到空格或者"或者结束
        }
        cout << count << endl;
        for (auto item : vec)
        {
            cout << item << endl;
        }
    }

    return 0;
}