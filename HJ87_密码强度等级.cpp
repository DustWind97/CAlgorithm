#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

//统计密码长度得分
int LenScore(string str)
{
    // int score;
    int len = str.length();
    if (len <= 4)
    {
        return 5;
    }
    else if (len >= 5 && len <= 7)
    {
        return 10;
    }
    return 25;
}

//统计字母得分
int ChScore(string str)
{
    int upper = 0, lower = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            upper++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            lower++;
        }
    }

    if (lower > 0 && upper > 0)
    {
        return 20;
    }
    else if ((lower > 0 && upper == 0) || (lower == 0 && upper > 0))
    {
        return 10;
    }
    return 0;
}

//统计数字得分
int NumScore(string str)
{
    int numCount = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            numCount++;
        }
    }

    if (numCount > 1)
    {
        return 20;
    }
    else if (numCount == 1)
    {
        return 10;
    }
    return 0;
}

//统计符号得分
/*
a-z                                         97-122
A-Z                                         65-90
0-9                                         48-57
!"#$%&'()*+,-./     (ASCII码：0x21~0x2F)    33-47   0-14
:;<=>?@             (ASCII码：0x3A~0x40)    58-64   25-31
[\]^_`              (ASCII码：0x5B~0x60)    91-96   55-63
{|}~                (ASCII码：0x7B~0x7E)    123-126 90-93
*/
int SignalScore(string str)
{
    int signalnum=0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '!' && str[i] <= '/')
        {
            signalnum++;
        }
        else if (str[i] >= ':' && str[i] <= '@')
        {
            signalnum++;
        }
        else if (str[i] >= '[' && str[i] <= '`')
        {
            signalnum++;
        }
        else if (str[i] >= '{' && str[i] <= '`')
        {
            signalnum++;
        }
    }

    if (signalnum > 1)
    {
        return 25;
    }
    else if (signalnum == 1)
    {
        return 10;
    }
    return 0;
}

//奖励得分
int AwardScore(string str)
{
    int chScore = ChScore(str);                            // 10 20
    int numScore = NumScore(str);                          // 10 20(>0分)
    int signalScore = SignalScore(str);                    // 10 25(>0分)
    if (chScore == 10 && numScore > 0 && signalScore == 0) // 2
    {
        return 2;
    }
    else if (chScore == 10 && numScore > 0 && signalScore > 0) // 3
    {
        return 3;
    }
    else if (chScore == 20 && numScore > 0 && signalScore > 0) // 4
    {
        return 5;
    }
    return 0;
}

//统计总的等级
string Overall(int lenScore, int chScore, int numScore, int signalScore, int awardScore)
{
    int score = 0;
    score = lenScore + chScore + numScore + signalScore + awardScore;
    if (score >= 90)
    {
        return "VERY_SECURE";
    }
    else if (score >= 80)
    {
        return "SECURE";
    }
    else if (score >= 70)
    {
        return "VERY_STRONG";
    }
    else if (score >= 60)
    {
        return "STRONG";
    }
    else if (score >= 50)
    {
        return "AVERAGE";
    }
    else if (score >= 25)
    {
        return "WEAK";
    }
    return "VERY_WEAK";
}

int main()
{
    string str;
    while (cin >> str)
    {
        string output = "";
        output = Overall(LenScore(str), ChScore(str), NumScore(str), SignalScore(str), AwardScore(str));
        cout << output << endl;
    }

    return 0;
}
