#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

//分割字符串
vector<string> splitstr(string str, char mark)
{
    vector<string> vec;
    string subStr;

    //遍历字符串，同时将i位置的字符放入到子串中，当遇到tag（需要切割的字符时）完成一次切割
    //遍历结束之后即可得到切割后的字符串数组
    for (size_t i = 0; i < str.length(); i++)
    {
        if (mark == str[i]) //完成一次切割
        {
            if (!subStr.empty())
            {
                vec.push_back(subStr);
                subStr.clear();
            }
        }
        else //将i位置的字符放入子串
        {
            subStr.push_back(str[i]);
        }
    }

    if (!subStr.empty()) //剩余的子串作为最后的子字符串
    {
        vec.push_back(subStr);
    }
    return vec;
}

// ip转化成比特流
string IP2BitStream(string ip)
{
    string bitstr; //比特流
    bitstr.clear();
    vector<string> vec;
    vec = splitstr(ip, '.'); //分割ip并存放各个元素到vec当中
    for (string str : vec)
    {
        int num = atoi(str.c_str());
        bitset<8> numbit;
        numbit = bitset<8>(num);
        bitstr += numbit.to_string();
    }
    return bitstr;
}

// ip合法性检测
bool ipcheck(string ip)
{
    //分段检测是否属于0-255范围
    vector<string> vec;
    vec = splitstr(ip, '.');
    if (vec.size() != 4)
    {
        return false;
    }
    for (string str : vec)
    {
        if (str[0] == '0' && str.length() > 1)
        {
            return false;
        }
        if (str[0] < '0' || str[0] > '9')
        {
            return false;
        }
    }
    for (string str : vec)
    {
        int num = atoi(str.c_str());
        if (num < 0 || num > 255)
        {
            return false;
        }
    }
    return true;
}

//掩码合法性检测
bool maskcheck(string mask)
{
    //首先分段检测是否符合ip
    if (ipcheck(mask))
    {
        //然后判断是否是连续多个1组成
        string bitstr; //比特流
        bitstr = IP2BitStream(mask);
        //统计1的个数
        int onenum = 0;
        for (int i = 0; i < bitstr.length(); i++)
        {
            if (bitstr[i] == '1')
            {
                onenum++;
            }
        }

        //判断是否是连续多个1组成
        for (int i = 0; i < onenum; i++)
        {
            if (bitstr[i] == '0')
            {
                return false; //但凡有一个不是1则掩码就不合法
            }
        }
        return true; //前面全是1
    }
    return false; //连ip地址都不合法
}

//判定是否私有地址
bool JudgePrivate(string ip)
{
    long ipnunm = atol(IP2BitStream(ip).c_str());

    // A类
    if (ipnunm >= atol(IP2BitStream("10.0.0.0").c_str()) &&
        ipnunm <= atol(IP2BitStream("10.255.255.255").c_str()))
    {
        return true;
    }
    // B类
    else if (ipnunm >= atol(IP2BitStream("172.16.0.0").c_str()) &&
             ipnunm <= atol(IP2BitStream("172.31.255.255").c_str()))
    {
        return true;
    }
    // 类
    else if (ipnunm >= atol(IP2BitStream("192.168.0.0").c_str()) &&
             ipnunm <= atol(IP2BitStream("192.168.255.255").c_str()))
    {
        return true;
    }
    return false; //其他不满足的IP地址
}

//判定ip的类别
string JudgeType(string ip)
{
    long ipnunm = atol(IP2BitStream(ip).c_str());

    // A类
    if (ipnunm >= atol(IP2BitStream("1.0.0.0").c_str()) &&
        ipnunm <= atol(IP2BitStream("126.255.255.255").c_str()))
    {
        return "A";
    }
    // B类
    else if (ipnunm >= atol(IP2BitStream("128.0.0.0").c_str()) &&
             ipnunm <= atol(IP2BitStream("191.255.255.255").c_str()))
    {
        return "B";
    }
    // C类
    else if (ipnunm >= atol(IP2BitStream("192.0.0.0").c_str()) &&
             ipnunm <= atol(IP2BitStream("223.255.255.255").c_str()))
    {
        return "C";
    }
    // D类
    else if (ipnunm >= atol(IP2BitStream("224.0.0.0").c_str()) &&
             ipnunm <= atol(IP2BitStream("239.255.255.255").c_str()))
    {
        return "D";
    }
    // E类
    else if (ipnunm >= atol(IP2BitStream("240.0.0.0").c_str()) &&
             ipnunm <= atol(IP2BitStream("255.255.255.255").c_str()))
    {
        return "E";
    }
    return "OTHER"; //其他不满足的IP地址
}

int main()
{
    string input;
    vector<string> vec;
    //统计各类地址的个数
    int type_a = 0, type_b = 0, type_c = 0, type_d = 0, type_e = 0; //为ABCDE类ip
    int type_invalid = 0;                                           //非法IP或者掩码
    int type_private = 0;                                           //私有地址
    while (getline(cin, input)) //输入一串字符串组，以~为区分
    {
        vec.push_back(input);
        input.clear();
    }

    //对vec进行处理
    vector<string> ip_vec;
    vector<string> mask_vec;
    for (int i = 0; i < vec.size(); i++)
    {
        string ip = "", mask = "";
        ip = vec[i].substr(0, vec[i].find('~'));
        mask = vec[i].substr(vec[i].find('~') + 1, vec[i].length() - vec[i].find('~'));
        ip_vec.push_back(ip);
        mask_vec.push_back(mask);
    }

    
    for (int i = 0; i < ip_vec.size(); i++)
    {
        //判定ABCDE类ip
        string type = JudgeType(ip_vec[i]);
        if (type == "A")
        {
            type_a++;
        }
        else if (type == "B")
        {
            type_b++;
        }
        else if (type == "C")
        {
            type_c++;
        }
        else if (type == "D")
        {
            type_d++;
        }
        else if (type == "E")
        {
            type_e++;
        }

        //判定是否合法ip以及合法掩码
        if (ipcheck(ip_vec[i]) == false)
        {
            type_invalid++;
        }
        if (maskcheck(mask_vec[i]) == false)
        {
            type_invalid++;
        }

        //判定是否私有地址
        if (JudgePrivate(ip_vec[i]) == true)
        {
            type_private++;
        }
    }
    cout << type_a << " " << type_b << " " << type_c << " " << type_d << " " << type_e << " " << type_invalid << " " << type_private << endl;

    return 0;
}