#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>

using namespace std;

int main()
{

    string oldletter = "abcdefghijklmnopqrstuvwxyz";//字符字典
    string newletter;
    string key_input, key_switched, info_input, info_output; //密钥key,待加密信息info_input,已加密信息info_output;
    cin >> key_input >> info_input;

    //对key进行处理
    unordered_map<char, int> dict;
    deque<char> deq;
    for (int i = 0; i < key_input.length(); i++)
    {
        if (dict.find(tolower(key_input[i])) == dict.end())
        {
            deq.push_back(tolower(key_input[i]));
        }
        ++dict[tolower(key_input[i])];
    }
    // for (unordered_map<char, int>::iterator it = dict.begin(); it != dict.end(); it++)//遍历是按照中序遍历的
    // {
    //     key_switched += it->first;
    // }
    for (auto ch : deq)
    {
        key_switched += ch;
    }

    string temp;
    temp.clear();
    for (int i = 0; i < oldletter.length(); i++)
    {
        if (key_switched.find(oldletter[i]) == string::npos)
        {
            temp += oldletter[i];
        }
        else
        {
            continue;
        }
    }

    newletter = key_switched + temp;

    // cout << key_switched << " | " << temp << endl;

    //开始处理信息
    for (int i = 0; i < info_input.length(); i++)
    {
        int pos = oldletter.find(info_input[i]);
        info_output += newletter[pos];
    }
    cout << info_output << endl;

    return 0;
}