#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// I是否包含了R<i>
vector<int> isIncluede(vector<long> I, long Ri) //保存找到的下标
{
    vector<int> ouput;
    for (int i = 0; i < I.size(); i++)
    {
        if (to_string(I[i]).find(to_string(Ri)) != string::npos)
        {
            ouput.push_back(i); //保存下标
        }
    }
    return ouput;
}

int main()
{
    //录入一组输入整数序列I
    long i_n;
    cin >> i_n;
    vector<long> vec_i;
    for (int i = 0; i < i_n; i++)
    {
        long temp;
        cin >> temp;
        vec_i.push_back(temp);
    }

    //录入一组规则整数序列R
    long r_n;
    cin >> r_n;
    vector<long> vec_r;
    for (int i = 0; i < r_n; i++)
    {
        long temp;
        cin >> temp;
        vec_r.push_back(temp);
    }

    //对于I和R两个集合进行相关处理
    //首先对R进行排序去重处理
    sort(vec_r.begin(), vec_r.end());
    vec_r.erase(unique(vec_r.begin(), vec_r.end()), vec_r.end()); //删除重复元素

    // for (int i = 0; i < vec_r.size(); i++)
    // {
    //     cout << vec_r[i] << " ";
    // }

    /*
    输出条件：
    (1)先输出R<i>；
    (2)再输出满足条件的I的个数；
    (3)然后输出满足条件的I在I序列中的位置索引(从0开始)；
    (4)最后再输出I。
    附加条件：
    (1)R<i>需要从小到大排序。相同的R<i>只需要输出索引小的以及满足条件的I，索引大的需要过滤掉
    (2)如果没有满足条件的I，对应的R<i>不用输出
    (3)最后需要在输出序列的第一个整数位置记录后续整数序列的个数(不包含“个数”本身)
    */
    //从R中取出R[i]对I进行处理
    vector<vector<int>> vec; //保存找到的下标
    // vector<int> out_i;       //下标个数与R[i]对应
    vector<int> out_r_legal; //在I中找到对应条件元素的R值

    for (int i = 0; i < vec_r.size(); i++)
    {
        vector<int> temp;
        temp.clear();
        temp = isIncluede(vec_i, vec_r[i]);
        if (temp.size() != 0) //找到
        {
            vec.push_back(temp); //下标集合打包放入vec中
            out_r_legal.push_back(vec_r[i]);
        }
    }

    //最后按要求输出
    int overall = 0;
    overall = out_r_legal.size() + vec.size();
    for (int i = 0; i < vec.size(); i++)
    {
        overall += (vec[i].size() * 2);
    }

    cout << overall << " ";

    for (int i = 0; i < vec.size(); i++)
    {
        cout << out_r_legal[i] << " ";
        cout << vec[i].size() << " ";
        for (int j = 0; j < vec[i].size(); j++) 
        {
            //先输出下标
            cout << vec[i][j] << " ";
            //再输出下标对应的数值
            cout << vec_i[vec[i][j]] << " ";
        }
    }
    
    return 0;
}
