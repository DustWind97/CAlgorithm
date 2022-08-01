#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string str;
    cin >> str;
    //将输入字符串利用map映射统计每个字符的出现次数
    map<char, int> dict; //第一个为关键字（key）唯一即字符串中的每一个字符，第二个为关键字的值（value），用来存放每一个关键字出现在字符串中的次数
    // map<char,int>::iterator it;
    for (char ch : str)
    {
        dict[ch]++;
    }

    //遍历整个dict，统计最少的次数
    int min = 21;//原因是字符串最长为20，最初默认一个不可能达到的长度
    for (auto &ch : dict)
    {
        min = ch.second < min ? ch.second : min;
    }

    //遍历整个str，擦除最少的字符
    for (int i = 0; i < str.length(); ++i)
    {
        if (dict[str[i]]== min)
        {
            str.erase(str.begin() + i-1);//上一次减了一次以后长度减了一个
        }
    }
    cout << str << endl;

    return 0;
}