// #include <iostream>
// #include <string>
// #include <vector>
// #include <iomanip>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     //输入n个数字
//     vector<string> vec;
//     for (int i = 0; i < n; i++)
//     {
//         string temp;
//         cin >> temp;
//         vec.push_back(temp);
//         temp.clear();
//         // cout<<atoi(vec[i].c_str());
//     }
//     double sum = 0;
//     int counter = 0; // counter记录非负数个数
//     for (int i = 0; i < n; i++)
//     {
//         if (atoi(vec[i].c_str()) >= 0)
//         {
//             sum += atoi(vec[i].c_str());
//             counter++;
//         }
//     }
//     if (counter == 0)
//     {
//         cout << n << endl;
//         cout << "0.0" << endl;
//     }
//     else
//     {
//         cout << (n - counter) << endl;
//         cout << setiosflags(ios::fixed) << setprecision(1) << sum / (double)counter << endl;
//     }

//     return 0;
// }

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> vec;    //容器vec存放输入的整数
    while(cin>>n) {    //将输入的整数插入到容器vec中--------------输入非数字时退出
        vec.push_back(n);
    }
    int count = count_if(vec.begin(), vec.end(), [](int x) {return x<0;});    //count为容器vec中负数的个数
    cout<<count<<endl;    //输出负数的个数
    vector<int> pos0vec;    //容器pos0vec存放容器vec中非负的整数
    copy_if(vec.begin(), vec.end(), back_inserter(pos0vec), [](int x) {return x>=0;});    //将容器vec中非负整数拷贝到容器pos0vec中
    int length = pos0vec.size();    //length为容器pos0vec中的元素个数
    double average=0;    //平均值
    if(length>0) {
        average = accumulate(pos0vec.begin(), pos0vec.end(), 0.0);    //对容器pos0vec中的元素求和
        average /= length;    //计算平均值
    }
    cout<<fixed<<setprecision(1)<<average<<endl;    //输出平均值
    return 0;
} 
