#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

/*
解题思路：贪心算法，统计字符串每个字母的个数，并将每个字母的个数由大到小排列以后依次从26往小赋权重
*/
void MapSortOfValue(vector<pair<int, char>> &vec, map<char, int> &m)//为啥要取地址
{
    for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
        vec.push_back(make_pair(it->second, it->first));
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
}

void dealer(string str)
{
    map<char, int> dict; //统计每个字母的出现频率
    for (int i = 0; i < str.length(); i++)
    {
        ++dict[tolower(str[i])];
    }
    // for (auto elem:dict)
    // {
    //     cout<<elem.first<<":"<<elem.second<<endl;
    // }
    


    //把字典的value字段排序输出到一个vector中按照从大到小排列
    vector<pair<int, char>> vec;
    MapSortOfValue(vec, dict);

    // for (int i = 0; i < vec.size(); i++)
    // {
    //     cout << vec[i].first << ":" << vec[i].second << endl;
    // }

    //依次访问vector并输出权重加权和
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i].first * (26 - i);
    }
    cout << sum << endl;
}

int main()
{
    int n;
    // string str;
    // cin>>str;
    // dealer(str);
    while (cin >> n)
    {
        vector<string> input(n);
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];

            //处理每一个input[i]贪心算法
            dealer(input[i]);
        }
    }

    return 0;
}
