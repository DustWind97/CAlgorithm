#include <iostream>
#include <string>
#include <vector>
#include <bitset>

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

/*
若IP地址或子网掩码格式非法则输出1，
若IP1与IP2属于同一子网络输出0，
若IP1与IP2不属于同一子网络输出2
*/
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

int main()
{
    string mask, ip1, ip2;
    cin >> mask >> ip1 >> ip2;

    while (cin >> mask >> ip1 >> ip2)
    {
        if ((!maskcheck(mask)) || (!ipcheck(ip1)) || (!ipcheck(ip2)))
        {
            cout << "1" << endl; //三个中有一个非法
        }
        else if (maskcheck(mask) && ipcheck(ip1) && ipcheck(ip2)) //三个均合法
        {
            // string maskbit = IP2BitStream(mask);
            // string ip1bit = IP2BitStream(ip1);
            // string ip2bit = IP2BitStream(ip2);

            // // cout << maskbit << " | " << ip1bit << " | " << ip2bit << endl;

            // long output1 = (atol(maskbit.c_str())) & (atol(ip1bit.c_str()));
            // long output2 = (atol(maskbit.c_str())) & (atol(ip2bit.c_str()));
            vector<string> vec_mask = splitstr(mask, '.');
            vector<string> vec_ip1 = splitstr(ip1, '.');
            vector<string> vec_ip2 = splitstr(ip2, '.');

            vector<int> output1, output2;

            for (int i = 0; i < 4; i++)
            {
                output1.push_back(atoi(vec_mask[i].c_str()) & atoi(vec_ip1[i].c_str()));
            }
            for (int i = 0; i < 4; i++)
            {
                output2.push_back(atoi(vec_mask[i].c_str()) & atoi(vec_ip2[i].c_str()));
            }

            int count = 0;
            for (int i = 0; i < 4; i++)
            {
                if (output1[i] == output2[i])
                {
                    count++;
                }
            }

            if (count == 4)
            {
                cout << "0" << endl; //在同一个子网中
            }
            else
            {
                cout << "2" << endl; //不在同一个子网中
            }
        }
    }

    return 0;
}