#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;
    string temp_num, temp_ch;
    temp_num.clear();
    temp_ch.clear();
    vector<string> vec;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            temp_num += str[i];
            // cout << temp<<" ";

            if (str[i + 1] < '0' || str[i + 1] > '9' || i == str.length() - 1)
            {
                vec.push_back(temp_num);
                temp_num.clear();
            }
        }
        else
        {
            temp_ch += str[i];
            if (str[i + 1] >= '0' && str[i + 1] <= '9' || i == str.length() - 1)
            {
                vec.push_back(temp_ch);
                temp_ch.clear();
            }
        }
    }

    string output = "";
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i][0] >= '0' && vec[i][0] <= '9')
        {
            output += ("*" + vec[i] + "*"); //数字字符串
        }
        else
        {
            output += vec[i]; //其他字符串
        }
    }
    cout << output << endl;

    return 0;
}