/*
本文系「人工智能安全」（微信公众号）原创，转载请联系本文作者（同博客作者）。
欢迎你转发分享至朋友圈，并给予「关注、星标、点赞」三连支持。互相欣赏，互相批判。
我是一名有诗人气质的网络安全工程师
期待与你的思想交流碰撞出智慧的花火
水木清华
2020-03-16
[中级]单词倒排
*/
#include <iostream>
#include <string>
#include <bits/stdc++.h>


using namespace std;

//单词倒排的函数接口
void Word_Rev_Sort(string str)
{
    vector<string> vec;   //用向量来存储单词
    int len = str.size(); //获取字符串的长度
    int sublen = 0;       //记录每个子字符串（单词）的长度
    //将句子中的单词分割，并将除最后一个单词之外的单词写入向量（如句子包含多个单词时）
    for (int i = 0; i < len; i++)
    {
        if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z')))
        {
            sublen++;
            continue;
        }
        else
        {
            if (sublen > 0)
            {
                vec.push_back(str.substr(i - sublen, sublen)); //将单词写入向量
                sublen = 0;                                    //重置单词的长度，记录下一个新单词的长度
            }
        }
    }
    //将最后一个单词写入向量，当句子仅有一个单词时同样适用
    if (sublen > 0)
    {
        vec.push_back(str.substr(len - sublen, sublen)); //将单词写入向量
    }

    //倒序输出单词，并用空格隔开，形成单词倒排的句子
    for (int i = vec.size() - 1; i > 0; i--)
    {
        cout << vec[i] << ' ';
    }
    cout << vec[0] << endl;
}
//主函数
int main()
{
    string str;
    while (getline(cin, str))
    {
        Word_Rev_Sort(str);
    }
    return 0;
}