#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
/*
功能实现如下2个通配符：
    *：匹配0个或以上的字符（注：能被*和?匹配的字符仅由英文字母和数字0到9组成，下同）
    ？：匹配1个字符
*/
bool match(const char *s, const char *p) // s为待匹配字符串，p为通配符字符串
{

    // base case 两个字符串同时结束,返回true
    if ((*p == '\0') && (*s == '\0'))
    {
        return true;
    }

    //两个字符串中有一个先结束，返回false
    if ((*p == '\0') || (*s == '\0'))
    {
        return false;
    }


    if (*p == '?')
    {

        //？只能匹配数字和字符，如果当前遇到了？，又遇到了其他字符，返回false
        if (!isdigit(*s) && !isalpha(*s))
            return false;

        //遇到到 ？ 则算匹配到一个字符，跳过一个位置
        return match(s + 1, p + 1);
    }
    else if (*p == '*')
    {
        //遇到连续多个*号，只有一个管作用(否则超时)
        while (*p == '*')
        {
            p++;
        }
        p--;

        //遇到*号,匹配0个（s不用动,p+1）,匹配1个（s和p都往前移动1位），匹配多个（s+1,p不用动）
        return match(s, p + 1) || match(s + 1, p + 1) || match(s + 1, p);
    }
    else if (tolower(*p) == tolower(*s))
    { 
        //大小写不敏感
        //当前两字符相等，则进行下一个字符的匹配
        return match(s + 1, p + 1);
    }

    return false; //不满足上述三种情况，不匹配
}

int main()
{
    string str_wildcard;
    string str_match;
    while (cin >> str_wildcard >> str_match)
    {
        bool res = match(str_match.c_str(), str_wildcard.c_str());
        if (res)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }

    return 0;
}