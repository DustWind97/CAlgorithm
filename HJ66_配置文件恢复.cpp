#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//处理匹配
string match(vector<string> vec) //设定匹配
{
    vector<pair<string, string>> cmd = {{"reset", ""},
                                        {"reset", "board"},
                                        {"board", "add"},
                                        {"board", "delete"},
                                        {"reboot", "backplane"},
                                        {"backplane", "abort"}}; //最后加一个无效指令he he
    vector<string> res = {"reset what",
                          "board fault",
                          "where to add",
                          "no board at all",
                          "impossible",
                          "install first"}; //最后加一个无效指令unknown command

    if (vec.size() == 1) //只有一个待匹配的关键词
    {
        //在cmd[0].first中查找
        if (cmd[0].first.find(vec[0]) == string::npos) //未匹配上
        {
            return "unknown command";
        }
        else //匹配上
        {
            return res[0];
        }
    }
    else if (vec.size() == 2) //有两个待匹配的关键词
    {
        // dp数组用于存放匹配成功与否
        vector<pair<bool, bool>> flag(6, make_pair(false, false)); //设置一个辅助数组用来存储是否满足条件，注意第一个用不上
        for (int i = 1; i < res.size(); i++)                       //跳过第一个
        {
            if (cmd[i].first.find(vec[0]) == 0) //匹配到第一关键字---注意是首字母开始匹配
            {
                flag[i].first = true;                //匹配到第一关键字，将dp数组的first字段置为1
                if (cmd[i].second.find(vec[1]) == 0) //匹配到第二个关键词---注意是首字母开始匹配
                {
                    flag[i].second = true; //匹配到第二关键字，再将dp数组的second字段置为1
                }
            }
        }

        //遍历dp数组
        int index = -1;  //保存找到的下标
        int counter = 0; //保存找到的个数
        for (int i = 1; i < flag.size(); i++)
        {
            if (flag[i].first == true && flag[i].second == true) //两个字段都匹配
            {
                counter++;
                index = i; //保存当前的下标
            }
        }

        if (counter == 1) //查找的唯一
        {
            return res[index];
        }
        else //不唯一
        {
            return "unknown command";
        }
    }

    return "unknown command"; //默认未匹配到,返回未找到
}

int main()
{
    string str;
    while (getline(cin, str))
    {
        //先将str分割
        vector<string> vec;
        if (str.find(" ") == string::npos) //没有找到空格说明是只有一个关键字
        {
            vec.push_back(str);
        }
        else //有两个关键词
        {
            string temp = str.substr(0, str.find(" "));
            vec.push_back(temp);
            temp.clear();
            temp = str.substr(str.find(" ") + 1, str.length() - str.find(" "));
            vec.push_back(temp);
        }

        string res = match(vec);
        cout << res << endl;
    }

    return 0;
}