#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//处理数据
vector<int> str2int(vector<string> vec)
{
    vector<int> vec_int;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == "A")
        {
            vec_int.push_back(1);
        }
        else if (vec[i] == "2")
        {
            vec_int.push_back(2);
        }
        else if (vec[i] == "3")
        {
            vec_int.push_back(3);
        }
        else if (vec[i] == "4")
        {
            vec_int.push_back(4);
        }
        else if (vec[i] == "5")
        {
            vec_int.push_back(5);
        }
        else if (vec[i] == "6")
        {
            vec_int.push_back(6);
        }
        else if (vec[i] == "7")
        {
            vec_int.push_back(7);
        }
        else if (vec[i] == "8")
        {
            vec_int.push_back(8);
        }
        else if (vec[i] == "9")
        {
            vec_int.push_back(9);
        }
        else if (vec[i] == "10")
        {
            vec_int.push_back(10);
        }
        else if (vec[i] == "J")
        {
            vec_int.push_back(11);
        }
        else if (vec[i] == "Q")
        {
            vec_int.push_back(12);
        }
        else if (vec[i] == "K")
        {
            vec_int.push_back(13);
        }
    }

    return vec_int;
}

/*
方法：DFS搜索（递归算法）
*/



int main()
{
    vector<string> vec_str;
    for (int i = 0; i < 4; i++)
    {
        string temp;
        cin >> temp;
        if (temp == "joker" || temp == "JOKER")
        {
            cout << "ERROR" << endl;
            break;
        }
        else
        {
            vec_str.push_back(temp);
        }
    }

    vector<int> vec_int = str2int(vec_str);

    //对vec_int进行处理
    


    return 0;
}